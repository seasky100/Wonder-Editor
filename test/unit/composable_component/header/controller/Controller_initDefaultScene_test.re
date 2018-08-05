open Wonderjs;

open Wonder_jest;

open Expect;

open Expect.Operators;

open Sinon;

let _ =
  describe("controller init default scene", () => {
    let sandbox = getSandboxDefaultVal();
    beforeEach(() => {
      sandbox := createSandbox();
      MainEditorSceneTool.initState(~sandbox, ());
      MainEditorSceneTool.createDefaultScene(
        sandbox,
        MainEditorSceneTool.setFirstBoxTobeCurrentSceneTreeNode,
      );
    });
    afterEach(() => restoreSandbox(refJsObjToSandbox(sandbox^)));

    describe("test ee engine state", () =>
      describe("add grid plane gameObject", () =>
        describe("test components", () => {
          describe("add custom geometry component", () =>
            test("test vertices, indices", () => {
              let engineState = StateLogicService.getEditEngineState();
              let gridPlaneGameObject =
                MainEditorSceneTool.getGridPlaneInDefaultScene(engineState);
              let customGeometry =
                GameObjectComponentEngineService.getGeometryComponent(
                  gridPlaneGameObject,
                  engineState,
                );

              (
                CustomGeometryEngineService.getCustomGeometryVertices(
                  customGeometry,
                  engineState,
                ),
                CustomGeometryEngineService.getCustomGeometryIndices(
                  customGeometry,
                  engineState,
                ),
              )
              |>
              expect == (
                          Js.Typed_array.Float32Array.make([|
                            (-200.),
                            0.,
                            (-200.),
                            200.,
                            0.,
                            (-200.),
                            (-200.),
                            0.,
                            (-200.),
                            (-200.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-194.),
                            200.,
                            0.,
                            (-194.),
                            (-194.),
                            0.,
                            (-200.),
                            (-194.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-188.),
                            200.,
                            0.,
                            (-188.),
                            (-188.),
                            0.,
                            (-200.),
                            (-188.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-182.),
                            200.,
                            0.,
                            (-182.),
                            (-182.),
                            0.,
                            (-200.),
                            (-182.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-176.),
                            200.,
                            0.,
                            (-176.),
                            (-176.),
                            0.,
                            (-200.),
                            (-176.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-170.),
                            200.,
                            0.,
                            (-170.),
                            (-170.),
                            0.,
                            (-200.),
                            (-170.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-164.),
                            200.,
                            0.,
                            (-164.),
                            (-164.),
                            0.,
                            (-200.),
                            (-164.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-158.),
                            200.,
                            0.,
                            (-158.),
                            (-158.),
                            0.,
                            (-200.),
                            (-158.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-152.),
                            200.,
                            0.,
                            (-152.),
                            (-152.),
                            0.,
                            (-200.),
                            (-152.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-146.),
                            200.,
                            0.,
                            (-146.),
                            (-146.),
                            0.,
                            (-200.),
                            (-146.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-140.),
                            200.,
                            0.,
                            (-140.),
                            (-140.),
                            0.,
                            (-200.),
                            (-140.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-134.),
                            200.,
                            0.,
                            (-134.),
                            (-134.),
                            0.,
                            (-200.),
                            (-134.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-128.),
                            200.,
                            0.,
                            (-128.),
                            (-128.),
                            0.,
                            (-200.),
                            (-128.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-122.),
                            200.,
                            0.,
                            (-122.),
                            (-122.),
                            0.,
                            (-200.),
                            (-122.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-116.),
                            200.,
                            0.,
                            (-116.),
                            (-116.),
                            0.,
                            (-200.),
                            (-116.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-110.),
                            200.,
                            0.,
                            (-110.),
                            (-110.),
                            0.,
                            (-200.),
                            (-110.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-104.),
                            200.,
                            0.,
                            (-104.),
                            (-104.),
                            0.,
                            (-200.),
                            (-104.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-98.),
                            200.,
                            0.,
                            (-98.),
                            (-98.),
                            0.,
                            (-200.),
                            (-98.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-92.),
                            200.,
                            0.,
                            (-92.),
                            (-92.),
                            0.,
                            (-200.),
                            (-92.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-86.),
                            200.,
                            0.,
                            (-86.),
                            (-86.),
                            0.,
                            (-200.),
                            (-86.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-80.),
                            200.,
                            0.,
                            (-80.),
                            (-80.),
                            0.,
                            (-200.),
                            (-80.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-74.),
                            200.,
                            0.,
                            (-74.),
                            (-74.),
                            0.,
                            (-200.),
                            (-74.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-68.),
                            200.,
                            0.,
                            (-68.),
                            (-68.),
                            0.,
                            (-200.),
                            (-68.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-62.),
                            200.,
                            0.,
                            (-62.),
                            (-62.),
                            0.,
                            (-200.),
                            (-62.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-56.),
                            200.,
                            0.,
                            (-56.),
                            (-56.),
                            0.,
                            (-200.),
                            (-56.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-50.),
                            200.,
                            0.,
                            (-50.),
                            (-50.),
                            0.,
                            (-200.),
                            (-50.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-44.),
                            200.,
                            0.,
                            (-44.),
                            (-44.),
                            0.,
                            (-200.),
                            (-44.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-38.),
                            200.,
                            0.,
                            (-38.),
                            (-38.),
                            0.,
                            (-200.),
                            (-38.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-32.),
                            200.,
                            0.,
                            (-32.),
                            (-32.),
                            0.,
                            (-200.),
                            (-32.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-26.),
                            200.,
                            0.,
                            (-26.),
                            (-26.),
                            0.,
                            (-200.),
                            (-26.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-20.),
                            200.,
                            0.,
                            (-20.),
                            (-20.),
                            0.,
                            (-200.),
                            (-20.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-14.),
                            200.,
                            0.,
                            (-14.),
                            (-14.),
                            0.,
                            (-200.),
                            (-14.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-8.),
                            200.,
                            0.,
                            (-8.),
                            (-8.),
                            0.,
                            (-200.),
                            (-8.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            (-2.),
                            200.,
                            0.,
                            (-2.),
                            (-2.),
                            0.,
                            (-200.),
                            (-2.),
                            0.,
                            200.,
                            (-200.),
                            0.,
                            4.,
                            200.,
                            0.,
                            4.,
                            4.,
                            0.,
                            (-200.),
                            4.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            10.,
                            200.,
                            0.,
                            10.,
                            10.,
                            0.,
                            (-200.),
                            10.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            16.,
                            200.,
                            0.,
                            16.,
                            16.,
                            0.,
                            (-200.),
                            16.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            22.,
                            200.,
                            0.,
                            22.,
                            22.,
                            0.,
                            (-200.),
                            22.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            28.,
                            200.,
                            0.,
                            28.,
                            28.,
                            0.,
                            (-200.),
                            28.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            34.,
                            200.,
                            0.,
                            34.,
                            34.,
                            0.,
                            (-200.),
                            34.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            40.,
                            200.,
                            0.,
                            40.,
                            40.,
                            0.,
                            (-200.),
                            40.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            46.,
                            200.,
                            0.,
                            46.,
                            46.,
                            0.,
                            (-200.),
                            46.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            52.,
                            200.,
                            0.,
                            52.,
                            52.,
                            0.,
                            (-200.),
                            52.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            58.,
                            200.,
                            0.,
                            58.,
                            58.,
                            0.,
                            (-200.),
                            58.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            64.,
                            200.,
                            0.,
                            64.,
                            64.,
                            0.,
                            (-200.),
                            64.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            70.,
                            200.,
                            0.,
                            70.,
                            70.,
                            0.,
                            (-200.),
                            70.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            76.,
                            200.,
                            0.,
                            76.,
                            76.,
                            0.,
                            (-200.),
                            76.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            82.,
                            200.,
                            0.,
                            82.,
                            82.,
                            0.,
                            (-200.),
                            82.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            88.,
                            200.,
                            0.,
                            88.,
                            88.,
                            0.,
                            (-200.),
                            88.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            94.,
                            200.,
                            0.,
                            94.,
                            94.,
                            0.,
                            (-200.),
                            94.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            100.,
                            200.,
                            0.,
                            100.,
                            100.,
                            0.,
                            (-200.),
                            100.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            106.,
                            200.,
                            0.,
                            106.,
                            106.,
                            0.,
                            (-200.),
                            106.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            112.,
                            200.,
                            0.,
                            112.,
                            112.,
                            0.,
                            (-200.),
                            112.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            118.,
                            200.,
                            0.,
                            118.,
                            118.,
                            0.,
                            (-200.),
                            118.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            124.,
                            200.,
                            0.,
                            124.,
                            124.,
                            0.,
                            (-200.),
                            124.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            130.,
                            200.,
                            0.,
                            130.,
                            130.,
                            0.,
                            (-200.),
                            130.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            136.,
                            200.,
                            0.,
                            136.,
                            136.,
                            0.,
                            (-200.),
                            136.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            142.,
                            200.,
                            0.,
                            142.,
                            142.,
                            0.,
                            (-200.),
                            142.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            148.,
                            200.,
                            0.,
                            148.,
                            148.,
                            0.,
                            (-200.),
                            148.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            154.,
                            200.,
                            0.,
                            154.,
                            154.,
                            0.,
                            (-200.),
                            154.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            160.,
                            200.,
                            0.,
                            160.,
                            160.,
                            0.,
                            (-200.),
                            160.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            166.,
                            200.,
                            0.,
                            166.,
                            166.,
                            0.,
                            (-200.),
                            166.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            172.,
                            200.,
                            0.,
                            172.,
                            172.,
                            0.,
                            (-200.),
                            172.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            178.,
                            200.,
                            0.,
                            178.,
                            178.,
                            0.,
                            (-200.),
                            178.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            184.,
                            200.,
                            0.,
                            184.,
                            184.,
                            0.,
                            (-200.),
                            184.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            190.,
                            200.,
                            0.,
                            190.,
                            190.,
                            0.,
                            (-200.),
                            190.,
                            0.,
                            200.,
                            (-200.),
                            0.,
                            196.,
                            200.,
                            0.,
                            196.,
                            196.,
                            0.,
                            (-200.),
                            196.,
                            0.,
                            200.,
                          |]),
                          Js.Typed_array.Uint16Array.make([|
                            0,
                            1,
                            2,
                            3,
                            4,
                            5,
                            6,
                            7,
                            8,
                            9,
                            10,
                            11,
                            12,
                            13,
                            14,
                            15,
                            16,
                            17,
                            18,
                            19,
                            20,
                            21,
                            22,
                            23,
                            24,
                            25,
                            26,
                            27,
                            28,
                            29,
                            30,
                            31,
                            32,
                            33,
                            34,
                            35,
                            36,
                            37,
                            38,
                            39,
                            40,
                            41,
                            42,
                            43,
                            44,
                            45,
                            46,
                            47,
                            48,
                            49,
                            50,
                            51,
                            52,
                            53,
                            54,
                            55,
                            56,
                            57,
                            58,
                            59,
                            60,
                            61,
                            62,
                            63,
                            64,
                            65,
                            66,
                            67,
                            68,
                            69,
                            70,
                            71,
                            72,
                            73,
                            74,
                            75,
                            76,
                            77,
                            78,
                            79,
                            80,
                            81,
                            82,
                            83,
                            84,
                            85,
                            86,
                            87,
                            88,
                            89,
                            90,
                            91,
                            92,
                            93,
                            94,
                            95,
                            96,
                            97,
                            98,
                            99,
                            100,
                            101,
                            102,
                            103,
                            104,
                            105,
                            106,
                            107,
                            108,
                            109,
                            110,
                            111,
                            112,
                            113,
                            114,
                            115,
                            116,
                            117,
                            118,
                            119,
                            120,
                            121,
                            122,
                            123,
                            124,
                            125,
                            126,
                            127,
                            128,
                            129,
                            130,
                            131,
                            132,
                            133,
                            134,
                            135,
                            136,
                            137,
                            138,
                            139,
                            140,
                            141,
                            142,
                            143,
                            144,
                            145,
                            146,
                            147,
                            148,
                            149,
                            150,
                            151,
                            152,
                            153,
                            154,
                            155,
                            156,
                            157,
                            158,
                            159,
                            160,
                            161,
                            162,
                            163,
                            164,
                            165,
                            166,
                            167,
                            168,
                            169,
                            170,
                            171,
                            172,
                            173,
                            174,
                            175,
                            176,
                            177,
                            178,
                            179,
                            180,
                            181,
                            182,
                            183,
                            184,
                            185,
                            186,
                            187,
                            188,
                            189,
                            190,
                            191,
                            192,
                            193,
                            194,
                            195,
                            196,
                            197,
                            198,
                            199,
                            200,
                            201,
                            202,
                            203,
                            204,
                            205,
                            206,
                            207,
                            208,
                            209,
                            210,
                            211,
                            212,
                            213,
                            214,
                            215,
                            216,
                            217,
                            218,
                            219,
                            220,
                            221,
                            222,
                            223,
                            224,
                            225,
                            226,
                            227,
                            228,
                            229,
                            230,
                            231,
                            232,
                            233,
                            234,
                            235,
                            236,
                            237,
                            238,
                            239,
                            240,
                            241,
                            242,
                            243,
                            244,
                            245,
                            246,
                            247,
                            248,
                            249,
                            250,
                            251,
                            252,
                            253,
                            254,
                            255,
                            256,
                            257,
                            258,
                            259,
                            260,
                            261,
                            262,
                            263,
                            264,
                            265,
                            266,
                            267,
                          |]),
                        );
            })
          );
          describe("add meshRenderer component", () =>
            test("drawMode should be Lines", () => {
              let engineState = StateLogicService.getEditEngineState();
              let gridPlaneGameObject =
                MainEditorSceneTool.getGridPlaneInDefaultScene(engineState);

              engineState
              |> GameObjectComponentEngineService.getMeshRendererComponent(
                   gridPlaneGameObject,
                 )
              |. MeshRendererEngineService.getDrawMode(engineState)
              |>
              expect == (
                          Wonderjs.DrawModeType.Lines
                          |> Wonderjs.DrawModeType.drawModeToUint8
                        );
            })
          );
          test("add basic material component", () => {
            let engineState = StateLogicService.getEditEngineState();
            let gridPlaneGameObject =
              MainEditorSceneTool.getGridPlaneInDefaultScene(engineState);

            engineState
            |> GameObjectComponentEngineService.hasBasicMaterialComponent(
                 gridPlaneGameObject,
               )
            |> expect == true;
          });
        })
      )
    );
  });