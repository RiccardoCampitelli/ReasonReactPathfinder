'use strict';

var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var Pathfinder$ReasonReactExamples = require("./Pathfinder/Pathfinder.bs.js");

ReactDOMRe.renderToElementWithId(React.createElement(Pathfinder$ReasonReactExamples.make, { }), "root");

/*  Not a pure module */
