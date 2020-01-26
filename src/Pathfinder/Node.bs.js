'use strict';

var Css = require("bs-css/src/Css.js");
var React = require("react");

function node(status) {
  var tmp;
  switch (status.tag | 0) {
    case /* Checked */0 :
        tmp = status[0] ? Css.darkblue : Css.papayawhip;
        break;
    case /* Wall */1 :
        tmp = status[0] ? Css.blue : Css.papayawhip;
        break;
    case /* Path */2 :
        tmp = status[0] ? Css.lightyellow : Css.papayawhip;
        break;
    case /* Empty */3 :
        tmp = Css.papayawhip;
        break;
    
  }
  return Css.style(/* :: */[
              Css.height(/* `px */[
                    25096,
                    15
                  ]),
              /* :: */[
                Css.width(/* `px */[
                      25096,
                      15
                    ]),
                /* :: */[
                  Css.outline(/* `px */[
                        25096,
                        1
                      ], /* solid */12956715, Css.black),
                  /* :: */[
                    Css.backgroundColor(tmp),
                    /* :: */[
                      Css.cursor(/* pointer */-786317123),
                      /* [] */0
                    ]
                  ]
                ]
              ]
            ]);
}

var Styles = {
  node: node
};

function preventDragHandler(_event) {
  _event.preventDefault();
  return /* () */0;
}

function $$Node(Props) {
  var status = Props.status;
  var onClick = Props.onClick;
  var onMouseEnter = Props.onMouseEnter;
  return React.createElement("div", {
              className: node(status),
              onClick: onClick,
              onDragStart: preventDragHandler,
              onMouseEnter: onMouseEnter
            });
}

var make = $$Node;

exports.Styles = Styles;
exports.preventDragHandler = preventDragHandler;
exports.make = make;
/* Css Not a pure module */
