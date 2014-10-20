
var image = new Image();


function gameStart() {
    image.src = "HelloWorld.png";
    image.onload = function(){
        gameInit();
    }
}

var director;
var myScene;
var layer;
var sprite;
var context;
var texture;

function step() {
    requestAnimationFrame(step);
}

function gameInit() {
    director = cc2.Director.getInstance();
    var canvas = document.getElementById("gameCanvas");
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;
    var width = canvas.width;
    var height = canvas.height;

    var params = {
                    'stencil': true,
                    'preserveDrawingBuffer': true,
                    'antialias': true,
                    'alpha': false};
                // Try to grab the standard context. If it fails, fallback to experimental.
    context = canvas.getContext("webgl", params) || canvas.getContext("experimental-webgl", params);

    director.setContext(context);
    director.setAnimationInterval(1.0 / 60);

    myScene = new CCScene();
    myScene.doTest(image);

    director.runWithScene(myScene);

    step();
}

gameStart();
