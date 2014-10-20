
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
    layer = new CCLayer();
    
    var max = 1000;
    var stepX = width/max*4;
    var stepY = height/max*4;
    texture = new CCTexture2D();
    texture.initWithHTMLImageElement(image);

    for (var i =0; i<max; i++) {
        sprite = cc2.Sprite.create(texture);
        sprite.setPosition(width/2, height/2);
        var action;
        var arch = 2*Math.PI/max * i;
        var x = width/2 * Math.sin(arch);
        var y = width/2 * Math.cos(arch);
        action = cc2.MoveTo.create(3, x, y);
        layer.addChild(sprite);
        sprite.runAction(action);
    }

    myScene.addChild(layer);

    director.runWithScene(myScene);

    step();
}

gameStart();
