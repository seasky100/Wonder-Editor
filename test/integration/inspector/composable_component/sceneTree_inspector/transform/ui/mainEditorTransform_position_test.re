open Wonder_jest;

open Expect;

open Expect.Operators;

open Sinon;

open MainEditorTransform;

let _ =
  describe("MainEditorTransform position", () => {
    let sandbox = getSandboxDefaultVal();
    beforeEach(() => sandbox := createSandbox());
    afterEach(() => restoreSandbox(refJsObjToSandbox(sandbox^)));
    describe("test set currentSceneTreeNode", () => {
      beforeEach(() => {
        MainEditorSceneTool.initState(~sandbox, ());
        MainEditorSceneTool.createDefaultScene(
          sandbox,
          MainEditorSceneTool.setFirstBoxTobeCurrentSceneTreeNode,
        );
      });
      describe("changeX should set current gameObject local position's x", () => {
        test("set x value to floatInput", () => {
          let currentGameObjectTransform =
            GameObjectTool.getCurrentSceneTreeNodeTransform();
          let value = "-10.1213";
          let component =
            BuildComponentTool.buildMainEditorTransformComponent(
              TestTool.buildEmptyAppState(),
              currentGameObjectTransform,
            );
          BaseEventTool.triggerComponentEvent(
            component,
            TransformEventTool.triggerChangePositionX(value),
          );
          BaseEventTool.triggerComponentEvent(
            component,
            TransformEventTool.triggerBlurPositionX(value),
          );
          component |> ReactTestTool.createSnapshotAndMatch;
        });
        describe("set engine x value", () => {
          describe(
            "if value's decimal digits <= 5, can set the whole value to engine",
            () => {
            test("test < 5", () => {
              let currentGameObjectTransform =
                GameObjectTool.getCurrentSceneTreeNodeTransform();
              let value = "-11.1111";
              let component =
                BuildComponentTool.buildMainEditorTransformComponent(
                  TestTool.buildEmptyAppState(),
                  currentGameObjectTransform,
                );
              BaseEventTool.triggerComponentEvent(
                component,
                TransformEventTool.triggerChangePositionX(value),
              );
              let (xFromEngine, _, _) =
                TransformUtils.getTransformPositionData(
                  currentGameObjectTransform,
                );

              expect(xFromEngine) == (value |> float_of_string);
            });
            test("test = 5", () => {
              let currentGameObjectTransform =
                GameObjectTool.getCurrentSceneTreeNodeTransform();
              let value = "-11.11112";
              let component =
                BuildComponentTool.buildMainEditorTransformComponent(
                  TestTool.buildEmptyAppState(),
                  currentGameObjectTransform,
                );
              BaseEventTool.triggerComponentEvent(
                component,
                TransformEventTool.triggerChangePositionX(value),
              );
              let (xFromEngine, _, _) =
                TransformUtils.getTransformPositionData(
                  currentGameObjectTransform,
                );
              expect(xFromEngine) == (value |> float_of_string);
            });
          });
          describe("else", () => {
            test("can't set the value to engine", () => {
              let currentGameObjectTransform =
                GameObjectTool.getCurrentSceneTreeNodeTransform();
              let value = "-14.6613123";
              let component =
                BuildComponentTool.buildMainEditorTransformComponent(
                  TestTool.buildEmptyAppState(),
                  currentGameObjectTransform,
                );
              BaseEventTool.triggerComponentEvent(
                component,
                TransformEventTool.triggerChangePositionX(value),
              );
              let (xFromEngine, _, _) =
                TransformUtils.getTransformPositionData(
                  currentGameObjectTransform,
                );

              expect(xFromEngine) == 0.;
            });
            test("get the x from engine should == last value", () => {
              let currentGameObjectTransform =
                GameObjectTool.getCurrentSceneTreeNodeTransform();
              let component =
                BuildComponentTool.buildMainEditorTransformComponent(
                  TestTool.buildEmptyAppState(),
                  currentGameObjectTransform,
                );
              let value1 = "-1.11222";
              let value2 = "-14.6613123";
              BaseEventTool.triggerComponentEvent(
                component,
                TransformEventTool.triggerChangePositionX(value1),
              );
              BaseEventTool.triggerComponentEvent(
                component,
                TransformEventTool.triggerChangePositionX(value2),
              );
              let (xFromEngine, _, _) =
                TransformUtils.getTransformPositionData(
                  currentGameObjectTransform,
                );

              expect(xFromEngine) == (value1 |> float_of_string);
            });
          });
        });
      });
      describe("changeY should set current gameObject local position's y", () => {
        test("set y value to floatInput", () => {
          let currentGameObjectTransform =
            GameObjectTool.getCurrentSceneTreeNodeTransform();
          let value = "25.21246";
          let component =
            BuildComponentTool.buildMainEditorTransformComponent(
              TestTool.buildEmptyAppState(),
              currentGameObjectTransform,
            );
          BaseEventTool.triggerComponentEvent(
            component,
            TransformEventTool.triggerChangePositionY(value),
          );
          component |> ReactTestTool.createSnapshotAndMatch;
        });
        describe("set engine y value", () => {
          test(
            "if value's decimal digits <= 5, can set the whole value to engine",
            () => {
            let currentGameObjectTransform =
              GameObjectTool.getCurrentSceneTreeNodeTransform();
            let value = "-11.11112";
            let component =
              BuildComponentTool.buildMainEditorTransformComponent(
                TestTool.buildEmptyAppState(),
                currentGameObjectTransform,
              );
            BaseEventTool.triggerComponentEvent(
              component,
              TransformEventTool.triggerChangePositionY(value),
            );
            let (_, yFromEngine, _) =
              TransformUtils.getTransformPositionData(
                currentGameObjectTransform,
              );

            expect(yFromEngine) == (value |> float_of_string);
          });
          test("if value is empty ", () => {
            let currentGameObjectTransform =
              GameObjectTool.getCurrentSceneTreeNodeTransform();
            let value = "";
            let component =
              BuildComponentTool.buildMainEditorTransformComponent(
                TestTool.buildEmptyAppState(),
                currentGameObjectTransform,
              );
            BaseEventTool.triggerComponentEvent(
              component,
              TransformEventTool.triggerChangePositionY(value),
            );
            let (_, yFromEngine, _) =
              TransformUtils.getTransformPositionData(
                currentGameObjectTransform,
              );

            expect(yFromEngine) == 0.;
          });
          test("else, get the y from engine should == last value", () => {
            let currentGameObjectTransform =
              GameObjectTool.getCurrentSceneTreeNodeTransform();
            let component =
              BuildComponentTool.buildMainEditorTransformComponent(
                TestTool.buildEmptyAppState(),
                currentGameObjectTransform,
              );
            let value1 = "-1.11222";
            let value2 = "-14.66132133";
            BaseEventTool.triggerComponentEvent(
              component,
              TransformEventTool.triggerChangePositionY(value1),
            );
            BaseEventTool.triggerComponentEvent(
              component,
              TransformEventTool.triggerChangePositionY(value2),
            );
            let (_, yFromEngine, _) =
              TransformUtils.getTransformPositionData(
                currentGameObjectTransform,
              );

            expect(yFromEngine) == (value1 |> float_of_string);
          });
        });
      });
      describe("changeZ should set current gameObject local position's z", () => {
        test("set z value to floatInput", () => {
          let currentGameObjectTransform =
            GameObjectTool.getCurrentSceneTreeNodeTransform();
          let value = "155.2164";
          let component =
            BuildComponentTool.buildMainEditorTransformComponent(
              TestTool.buildEmptyAppState(),
              currentGameObjectTransform,
            );
          BaseEventTool.triggerComponentEvent(
            component,
            TransformEventTool.triggerChangePositionZ(value),
          );
          component |> ReactTestTool.createSnapshotAndMatch;
        });
        describe("set engine z value", () => {
          test(
            "if value's decimal digits <= 5, can set the whole value to engine",
            () => {
            let currentGameObjectTransform =
              GameObjectTool.getCurrentSceneTreeNodeTransform();
            let value = "-11.11112";
            let component =
              BuildComponentTool.buildMainEditorTransformComponent(
                TestTool.buildEmptyAppState(),
                currentGameObjectTransform,
              );
            BaseEventTool.triggerComponentEvent(
              component,
              TransformEventTool.triggerChangePositionZ(value),
            );
            let (_, _, zFromEngine) =
              TransformUtils.getTransformPositionData(
                currentGameObjectTransform,
              );

            expect(zFromEngine) == (value |> float_of_string);
          });
          test("else, get the z from engine should == last value", () => {
            let currentGameObjectTransform =
              GameObjectTool.getCurrentSceneTreeNodeTransform();
            let component =
              BuildComponentTool.buildMainEditorTransformComponent(
                TestTool.buildEmptyAppState(),
                currentGameObjectTransform,
              );
            let value1 = "-1.23435";
            let value2 = "-24.6613123";
            BaseEventTool.triggerComponentEvent(
              component,
              TransformEventTool.triggerChangePositionZ(value1),
            );
            BaseEventTool.triggerComponentEvent(
              component,
              TransformEventTool.triggerChangePositionZ(value2),
            );
            let (_, _, zFromEngine) =
              TransformUtils.getTransformPositionData(
                currentGameObjectTransform,
              );

            expect(zFromEngine) == (value1 |> float_of_string);
          });
        });
      });
    });
  });