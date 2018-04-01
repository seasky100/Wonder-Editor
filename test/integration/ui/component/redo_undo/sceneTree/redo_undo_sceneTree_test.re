open Wonder_jest;

open Expect;

open Expect.Operators;

open Sinon;

let _ =
  describe(
    "redo_undo: sceneTree",
    () => {
      let sandbox = getSandboxDefaultVal();
      beforeEach(() => sandbox := createSandbox());
      afterEach(() => restoreSandbox(refJsObjToSandbox(sandbox^)));
      describe(
        "get scene tree from engine",
        () => {
          let _simulateTwiceDragEvent = () => {
            let component =
              BuildComponentTool.buildSceneTree(SceneTreeTool.buildAppStateSceneGraphFromEngine());
            BaseEventTool.triggerComponentEvent(component, SceneTreeEventTool.triggerDragStart(2));
            BaseEventTool.triggerComponentEvent(component, SceneTreeEventTool.triggerDragEnter(0));
            BaseEventTool.triggerComponentEvent(component, SceneTreeEventTool.triggerDragDrop(0));
            let component2 =
              BuildComponentTool.buildSceneTree(SceneTreeTool.buildAppStateSceneGraphFromEngine());
            BaseEventTool.triggerComponentEvent(
              component2,
              SceneTreeEventTool.triggerDragStart(1)
            );
            BaseEventTool.triggerComponentEvent(
              component2,
              SceneTreeEventTool.triggerDragEnter(0)
            );
            BaseEventTool.triggerComponentEvent(component2, SceneTreeEventTool.triggerDragDrop(0))
          };
          beforeEach(
            () => {
              TestTool.closeContractCheck();
              TestTool.initMainEditor(sandbox);
              MainEditorSceneTool.prepareDefaultScene(
                MainEditorSceneTool.setFirstBoxTobeCurrentGameObject
              );
              StateHistoryToolEditor.clearAllState()
            }
          );
          afterEach(() => TestTool.openContractCheck());
          describe(
            "test snapshot",
            () => {
              describe(
                "test undo operate",
                () => {
                  test(
                    "test not undo",
                    () => {
                      _simulateTwiceDragEvent();
                      BuildComponentTool.buildSceneTree(
                        SceneTreeTool.buildAppStateSceneGraphFromEngine()
                      )
                      |> ReactTestTool.createSnapshotAndMatch
                    }
                  );
                  describe(
                    "test undo one step",
                    () =>
                      test(
                        "step from second to first",
                        () => {
                          _simulateTwiceDragEvent();
                          /* the undo function not exec */
                          StateHistoryToolEditor.undo();
                          BuildComponentTool.buildSceneTree(
                            SceneTreeTool.buildAppStateSceneGraphFromEngine()
                          )
                          |> ReactTestTool.createSnapshotAndMatch
                        }
                      )
                  );
                  describe(
                    "test undo two step",
                    () =>
                      test(
                        "step from second to zero",
                        () => {
                          _simulateTwiceDragEvent();
                          StateHistoryToolEditor.undo();
                          StateHistoryToolEditor.undo();
                          BuildComponentTool.buildSceneTree(
                            SceneTreeTool.buildAppStateSceneGraphFromEngine()
                          )
                          |> ReactTestTool.createSnapshotAndMatch
                        }
                      )
                  );
                  describe(
                    "test undo three step",
                    () =>
                      test(
                        "if current step is zero, undo should do nothing",
                        () => {
                          _simulateTwiceDragEvent();
                          StateHistoryToolEditor.undo();
                          StateHistoryToolEditor.undo();
                          StateHistoryToolEditor.undo();
                          BuildComponentTool.buildSceneTree(
                            SceneTreeTool.buildAppStateSceneGraphFromEngine()
                          )
                          |> ReactTestTool.createSnapshotAndMatch
                        }
                      )
                  )
                }
              );
              describe(
                "test redo operate",
                () => {
                  describe(
                    "test redo one step",
                    () => {
                      test(
                        "if not exec undo, redo one step should do nothing",
                        () => {
                          _simulateTwiceDragEvent();
                          StateHistoryToolEditor.redo();
                          BuildComponentTool.buildSceneTree(
                            SceneTreeTool.buildAppStateSceneGraphFromEngine()
                          )
                          |> ReactTestTool.createSnapshotAndMatch
                        }
                      );
                      test(
                        "undo step from second to zero, redo step from zero to first",
                        () => {
                          _simulateTwiceDragEvent();
                          StateHistoryToolEditor.undo();
                          StateHistoryToolEditor.undo();
                          StateHistoryToolEditor.redo();
                          BuildComponentTool.buildSceneTree(
                            SceneTreeTool.buildAppStateSceneGraphFromEngine()
                          )
                          |> ReactTestTool.createSnapshotAndMatch
                        }
                      )
                    }
                  );
                  describe(
                    "test redo two step",
                    () =>
                      test(
                        "undo step from second to zero, redo step from zero to second",
                        () => {
                          _simulateTwiceDragEvent();
                          StateHistoryToolEditor.undo();
                          StateHistoryToolEditor.undo();
                          StateHistoryToolEditor.redo();
                          StateHistoryToolEditor.redo();
                          BuildComponentTool.buildSceneTree(
                            SceneTreeTool.buildAppStateSceneGraphFromEngine()
                          )
                          |> ReactTestTool.createSnapshotAndMatch
                        }
                      )
                  );
                  describe(
                    "test redo three step",
                    () =>
                      test(
                        "test if current step is last step, redo should do nothing",
                        () => {
                          _simulateTwiceDragEvent();
                          StateHistoryToolEditor.undo();
                          StateHistoryToolEditor.undo();
                          StateHistoryToolEditor.redo();
                          StateHistoryToolEditor.redo();
                          StateHistoryToolEditor.redo();
                          BuildComponentTool.buildSceneTree(
                            SceneTreeTool.buildAppStateSceneGraphFromEngine()
                          )
                          |> ReactTestTool.createSnapshotAndMatch
                        }
                      )
                  )
                }
              )
            }
          )
        }
      )
    }
  );