'use strict';

var Css = require("bs-css/src/Css.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
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

function Pathfinder(Props) {
  var match = React.useState((function () {
          return createEmptyBoard(/* () */0);
        }));
  var setBoard = match[1];
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
  return React.createElement("div", {
              className: appContainer
            }, React.createElement("div", undefined, React.createElement("button", {
                      onClick: resetBoard
                    }, "Reset board")), React.createElement(Board$ReasonReactExamples.make, {
                  board: match[0],
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
exports.make = make;
/* appContainer Not a pure module */
