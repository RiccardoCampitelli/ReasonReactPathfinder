'use strict';

var Css = require("bs-css/src/Css.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Node$ReasonReactExamples = require("./Node.bs.js");

var gridContainer = Css.style(/* :: */[
      Css.display(/* flex */-1010954439),
      /* :: */[
        Css.justifyContent(/* center */98248149),
        /* [] */0
      ]
    ]);

var grid = Css.style(/* :: */[
      Css.display(/* flex */-1010954439),
      /* :: */[
        Css.flexWrap(/* wrap */-822134326),
        /* :: */[
          Css.width(/* `px */[
                25096,
                600
              ]),
          /* :: */[
            Css.height(/* `px */[
                  25096,
                  160
                ]),
            /* [] */0
          ]
        ]
      ]
    ]);

var Styles = {
  gridContainer: gridContainer,
  grid: grid
};

function Board(Props) {
  var board = Props.board;
  var setNodeStatus = Props.setNodeStatus;
  return React.createElement("div", {
              className: gridContainer
            }, React.createElement("div", {
                  className: grid
                }, $$Array.mapi((function (rowIndex, row) {
                        return $$Array.mapi((function (colIndex, status) {
                                      return React.createElement(Node$ReasonReactExamples.make, {
                                                  status: status,
                                                  onClick: (function (__x) {
                                                      var colIndex$1 = colIndex;
                                                      var rowIndex$1 = rowIndex;
                                                      return Curry._4(setNodeStatus, colIndex$1, rowIndex$1, /* Checked */Block.__(0, [true]), /* () */0);
                                                    }),
                                                  key: String(colIndex) + String(rowIndex)
                                                });
                                    }), row);
                      }), board)));
}

var make = Board;

exports.Styles = Styles;
exports.make = make;
/* gridContainer Not a pure module */
