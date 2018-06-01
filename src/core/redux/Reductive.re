module Store = {
  type t('action, 'state) = {
    mutable state: 'state,
    mutable reducer: ('state, 'action) => 'state,
    mutable listeners: list((unit => unit)),
    customDispatcher: option(((t('action, 'state), 'action => unit, 'action) => unit))
  };
  let create = (~reducer, ~preloadedState, ~enhancer=?, ()) =>
    switch (preloadedState, enhancer, reducer) {
    | (preloadedState, None, reducer) => {
        state: preloadedState,
        listeners: [],
        reducer,
        customDispatcher: None
      }
    | (preloadedState, Some(enhancer), reducer) => {
        state: preloadedState,
        listeners: [],
        reducer,
        customDispatcher: Some(enhancer)
      }
    };
  let unsubscribe = (store, listener, ()) =>
    store.listeners = List.filter((l) => listener !== l, store.listeners);
  let subscribe = (store, listener) => {
    store.listeners = [listener, ...store.listeners];
    unsubscribe(store, listener)
  };
  let nativeDispatch = (store, action) => {
    store.state = store.reducer(store.state, action);
    List.iter((listener) => listener(), store.listeners)
  };
  let dispatchFunc = (store, action) =>
    switch store.customDispatcher {
    | Some(customDispatcher) => customDispatcher(store, nativeDispatch(store), action)
    | None => nativeDispatch(store, action)
    };
  let getState = (store) => store.state;
  let replaceReducer = (store, reducer) => store.reducer = reducer;
};

module Provider = {
  type state('reductiveState) = {
    reductiveState: option('reductiveState),
    unsubscribe: option((unit => unit))
  };
  let createMake = (~name="Provider", store: Store.t('action, 'state)) => {
    let innerComponent = ReasonReact.reducerComponent(name);
    let make =
        (
          ~component:
             (~state: 'state, ~dispatchFunc: 'action => unit, array(ReasonReact.reactElement)) =>
             ReasonReact.component('a, 'b, 'c),
          _children: array(ReasonReact.reactElement)
        )
        : ReasonReact.component(state('state), ReasonReact.noRetainedProps, ReasonReact.actionless) => {
      let updater = (_, {ReasonReact.state}) =>
        ReasonReact.Update({...state, reductiveState: Some(Store.getState(store))});
      {
        ...innerComponent,
        initialState: () => {reductiveState: None, unsubscribe: None},
        didMount: ({update}) =>
          ReasonReact.Update({
            unsubscribe: Some(Store.subscribe(store, update(updater))),
            reductiveState: Some(Store.getState(store))
          }),
        willUnmount: ({state}) =>
          switch state.unsubscribe {
          | Some(unsubscribe) => unsubscribe()
          | None => ()
          },
        render: ({state}) =>
          switch state.reductiveState {
          | None => ReasonReact.nullElement
          | Some(state) =>
            ReasonReact.element(component(~state, 
            ~dispatchFunc=Store.dispatchFunc(store), [||]))
          }
      }
    };
    make
  };
};


/*** These are all visible apis of Redux that aren't needed in Reason.
 * When used, build tools will provide explaination of alternatives.
 * (see .rei for those)
 */
let compose = (_) => ();

let combineReducers = (_) => ();

let applyMiddleware = (_) => ();

let bindActionCreators = (actions, dispatchFunc) =>
  List.map((action, ()) => dispatchFunc(action), actions);
