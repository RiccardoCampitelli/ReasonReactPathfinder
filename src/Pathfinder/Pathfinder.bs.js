'use strict';

var Css = require("bs-css/src/Css.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Caml_obj = require("bs-platform/lib/js/caml_obj.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Board$ReasonReactExamples = require("./Board.bs.js");

var appContainer = Css.style(/* :: */[
      Css.position(/* absolute */-1013592457),
      /* :: */[
        Css.height(/* `vh */[
              26418,
              100
            ]),
        /* :: */[
          Css.width(/* `percent */[
                -119887163,
                100
              ]),
          /* [] */0
        ]
      ]
    ]);

var Styles = {
  appContainer: appContainer
};

function createEmptyBoard(param) {
  var initialBoard = $$Array.make_matrix(20, 20, /* Empty */Block.__(3, [true]));
  Caml_array.caml_array_set(Caml_array.caml_array_get(initialBoard, 8), 4, /* StartNode */Block.__(4, [true]));
  Caml_array.caml_array_set(Caml_array.caml_array_get(initialBoard, 9), 14, /* EndNode */Block.__(5, [true]));
  return initialBoard;
}

function updateNode(board, param, newStatus) {
  var y = param[1];
  var x = param[0];
  return $$Array.mapi((function (rowIndex, rowArray) {
                var match = rowIndex === y;
                if (match) {
                  return $$Array.mapi((function (colIndex, node) {
                                var match = colIndex === x;
                                if (match) {
                                  return newStatus;
                                } else {
                                  return node;
                                }
                              }), rowArray);
                } else {
                  return $$Array.copy(rowArray);
                }
              }), board);
}

function findInMatrix(matrix, _i, _j, pred) {
  while(true) {
    var j = _j;
    var i = _i;
    if (i >= matrix.length && j >= matrix.length) {
      return ;
    } else if (Curry._1(pred, Caml_array.caml_array_get(Caml_array.caml_array_get(matrix, i), j))) {
      return /* tuple */[
              i,
              j
            ];
    } else {
      var colIndexInRange = i < (matrix.length - 1 | 0);
      var rowIndexInRange = j < (matrix.length - 1 | 0);
      if (colIndexInRange) {
        if (rowIndexInRange) {
          _i = i + 1 | 0;
          continue ;
        } else {
          return ;
        }
      } else if (rowIndexInRange) {
        _j = j + 1 | 0;
        _i = 0;
        continue ;
      } else {
        return ;
      }
    }
  };
}

function getStartNodeCoords(board) {
  return findInMatrix(board, 0, 0, (function (value) {
                return Caml_obj.caml_equal(value, /* StartNode */Block.__(4, [true]));
              }));
}

function getEndNodeCoords(board) {
  return findInMatrix(board, 0, 0, (function (value) {
                return Caml_obj.caml_equal(value, /* EndNode */Block.__(5, [true]));
              }));
}

function Pathfinder(Props) {
  var match = React.useState((function () {
          return createEmptyBoard(/* () */0);
        }));
  var setBoard = match[1];
  var board = match[0];
  var setNodeStatus = function (col, row, newStatus) {
    return Curry._1(setBoard, (function (oldBoard) {
                  return updateNode(oldBoard, /* tuple */[
                              col,
                              row
                            ], newStatus);
                }));
  };
  var resetBoard = function (_event) {
    return Curry._1(setBoard, (function (param) {
                  return createEmptyBoard(/* () */0);
                }));
  };
  var test = function (param) {
    var startNode = getStartNodeCoords(board);
    var endNode = getEndNodeCoords(board);
    console.log(/* tuple */[
          startNode,
          endNode
        ]);
    return /* () */0;
  };
  return React.createElement("div", {
              className: appContainer
            }, React.createElement("div", undefined, React.createElement("button", {
                      onClick: resetBoard
                    }, "Reset board"), React.createElement("button", {
                      onClick: test
                    }, "Test")), React.createElement(Board$ReasonReactExamples.make, {
                  board: board,
                  setNodeStatus: setNodeStatus
                }));
}

var defaultBoardHeight = 20;

var defaultBoardWidth = 20;

var make = Pathfinder;

exports.Styles = Styles;
exports.defaultBoardHeight = defaultBoardHeight;
exports.defaultBoardWidth = defaultBoardWidth;
exports.createEmptyBoard = createEmptyBoard;
exports.updateNode = updateNode;
exports.findInMatrix = findInMatrix;
exports.getStartNodeCoords = getStartNodeCoords;
exports.getEndNodeCoords = getEndNodeCoords;
exports.make = make;
/* appContainer Not a pure module */
