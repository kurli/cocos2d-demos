/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2008-2010 Ricardo Quesada
 Copyright (c) 2011      Zynga Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

var MyLayer = cc.Layer.extend({
    isMouseDown:false,
    helloImg:null,
    helloLabel:null,
    circle:null,
    sprite:null,

    ctor:function() {
        this._super();
        cc.associateWithNative( this, cc.Layer );
    },

    init:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        /////////////////////////////
        // 2. add a menu item with "X" image, which is clicked to quit the program
        //    you may modify it.
        // ask director the window size

        /*
        var size = cc.Director.sharedDirector().getWinSize();

        var max = 1000;
        var width = size.width;
        var height = size.height;

        for (var i =0; i<max; i++) {
            var sprite = cc.Sprite.create(s_HelloWorld);
            sprite.setPosition(width/2, height/2);
            var action;
            var arch = 2*Math.PI/max * i;
            var x = width/2 * Math.sin(arch);
            var y = width/2 * Math.cos(arch);
            var p = new cc.Point(x, y);
            action = cc.MoveBy.create(3, p);
            var delay = new cc.DelayTime(0.25);
            var reverse = action.reverse();
            var sequence = cc.Sequence.create(action, delay, reverse);
            var repeat = cc.RepeatForever.create(sequence);
            this.addChild(sprite);
            sprite.runAction(repeat);

            var rotateForever = cc.RepeatForever.create(cc.RotateBy.create(3, 360));
            sprite.runAction(rotateForever);
        }

        return true;
        */
    }

});

var MyScene = cc.Scene.extend({
    ctor:function() {
        this._super();
        cc.associateWithNative( this, cc.Scene );
    },

    onEnter:function () {
        this._super();
        //var layer = new MyLayer();
        //this.addChild(layer);
        //layer.init();
        this.doTest();
        return true;
    },

        doTest:function() {
        var s = cc.Director.getInstance().getWinSize();

        var particleSystem = cc.ParticleSystem.createWithTotalParticles(3000);
        //cc.Texture2D.setDefaultAlphaPixelFormat(cc.TEXTURE_PIXELFORMAT_A8);
        particleSystem.setTexture(cc.TextureCache.getInstance().addImage(s_HelloWorld));
        this.addChild(particleSystem);

        // duration
        particleSystem.setDuration(-1);

        // gravity
        particleSystem.setGravity(cc.p(0, -90));

        // angle
        particleSystem.setAngle(90);
        particleSystem.setAngleVar(0);

        // radial
        particleSystem.setRadialAccel(0);
        particleSystem.setRadialAccelVar(0);

        // speed of particles
        particleSystem.setSpeed(180);
        particleSystem.setSpeedVar(50);

        // emitter position
        particleSystem.setPosition(s.width / 2, 100);
        particleSystem.setPosVar(cc.p(s.width / 2, 0));

        // life of particles
        particleSystem.setLife(2.0);
        particleSystem.setLifeVar(1);

        // emits per frame
        particleSystem.setEmissionRate(particleSystem.getTotalParticles() / particleSystem.getLife());

        // color of particles
        
        var startColor = cc.c4f(0.5, 0.5, 0.5, 1.0);
        particleSystem.setStartColor(startColor);

        var startColorVar = cc.c4f(0.5, 0.5, 0.5, 1.0);
        particleSystem.setStartColorVar(startColorVar);

        var endColor = cc.c4f(0.1, 0.1, 0.1, 0.2);
        particleSystem.setEndColor(endColor);

        var endColorVar = cc.c4f(0.1, 0.1, 0.1, 0.2);
        particleSystem.setEndColorVar(endColorVar);
        

        // size, in pixels
        particleSystem.setEndSize(32.0);
        particleSystem.setStartSize(32.0);
        particleSystem.setEndSizeVar(0);
        particleSystem.setStartSizeVar(0);

        // additive
        particleSystem.setBlendAdditive(false);
    }

});
