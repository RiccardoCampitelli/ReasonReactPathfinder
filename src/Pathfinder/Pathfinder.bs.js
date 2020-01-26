'use strict';

var Css = require("bs-css/src/Css.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
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
  return $$Array.make_matrix(20, 20, /* Empty */Block.__(3, [true]));
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
          return $$Array.make_matrix(20, 20, /* Empty */Block.__(3, [true]));
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
  return React.createElement("div", {
              className: appContainer
            }, React.createElement(Board$ReasonReactExamples.make, {
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
