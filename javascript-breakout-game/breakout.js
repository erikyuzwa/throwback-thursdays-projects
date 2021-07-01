const width = 640;
const height = 480;

let context;

let game_over = false;

// creating the ball
const ballRadius = 14;
let ball = {
    dx: 2,
    dy: 2,
    x: width / 2,
    y: height / 2,
    w: ballRadius,
    h: ballRadius
};

// paddle
const paddleWidth = 20;
const paddleHeight = 80;
let player = {
    score: 0,
    lives: 3,
    dx: 0,
    dy: 0,
    speed: 3,
    x: width - 30,
    y: height / 2,
    w: paddleWidth,
    h: paddleHeight
};


// brick array
let bricks = [];
let brickCount = 0;

for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 10; j++) {
        bricks[brickCount] = {
            x: i * 25,
            y: j * 40,
            w: 15,
            h: 35,
            alive: true
        }

        brickCount++;
    }
}

const render = function () {
    // clear canvas
    context.fillStyle = "#0000ee";
    context.fillRect(0, 0, width, height);

    renderBricks();

    renderBall();

    renderPlayer();

    renderText();

    if (player.lives < 1) {
        // game is over
        game_over = true;
    }

    window.requestAnimationFrame(render);

}

const renderPlayer = function () {

    let posx = player.x;
    let posy = player.y;

    posy = posy - (player.dy * player.speed);

    player.x = posx;
    player.y = posy;

    drawRect("#000000", player.x, player.y, player.w, player.h);
}

const renderBall = function () {

    if (ball.x + ballRadius < 0) {
        ball.dx = -ball.dx;
    } else if (ball.x + ballRadius > width) {
        player.lives--;
        ball.x = width / 2;
        ball.y = height / 2;
    }

    if (ball.y + ballRadius < 0 || ball.y + ballRadius > height) {
        ball.dy = -ball.dy;
    }

    if (isCollision(ball, player)) {
        ball.dx = -ball.dx;
        //ball.dy = -ball.dy;
    }

    if (!game_over) {
        ball.x += ball.dx;
        ball.y += ball.dy;
    }



    

    drawRect("#000000", ball.x, ball.y, ball.w, ball.h);
}

const renderBricks = function () {

    for (let i = 0; i < bricks.length; i++) {

        if (bricks[i].alive) {

            if (!isCollision(ball, bricks[i])) {
                drawRect("#ee00ee", bricks[i].x, bricks[i].y, bricks[i].w, bricks[i].h);
            } else {
                bricks[i].alive = false;
                player.score += 10;
            }
            
        }
    }
}

const renderText = function () {

    context.font = "30px Arial";
    context.fillStyle = "yellow";
    context.fillText("Score: " + player.score, width - 150, 40);
    context.fillText("Lives: " + player.lives, width - 275, 40);

    if (game_over) {
        context.font = "72px Arial";
        context.textAlign = "center";
        context.fillText("G A M E   O V E R", width / 2, height / 2);

        context.font = "24px Arial";
        context.fillText("Space to Restart", width / 2, height / 2 + 20);
    }

}

const isCollision = function(object1, object2) {
    if (object1.x + object1.w > object2.x && 
        object1.x < object2.x + object2.w &&
        object2.y + object2.h > object1.y &&
        object2.y < object1.y + object1.h) {

        return true;
    }

    return false;
}

const drawRect = function(color, x, y, w, h) {
    context.fillStyle = color;
    context.fillRect(x, y, w, h);
}

const KEY_DOWN = 40;
const KEY_UP = 38;
const KEY_SPACE = 32;

const onKeyUp = function(e) {
    console.log('onKeyUp', e);

    switch(e.keyCode) {
        case KEY_DOWN:
            if (!game_over) {
                player.dy = 0;
            }
            break;
        case KEY_UP:
            if (!game_over) {
                player.dy = 0;
            }
            break;
        case KEY_SPACE:
            if (game_over) {
                game_over = false;
                player.lives = 3;
                // TODO: reset the bricks, ball, and player
            }
            break;
    }

}

const onKeyDown = function(e) {
    console.log('onKeyDown', e);

    switch(e.keyCode) {
        case KEY_DOWN:
            if (!game_over) {
                player.dy = -1;
            }
            break;
        case KEY_UP:
            if (!game_over) {
                player.dy = 1;
            }
            break;
    }
}

window.onload = function () {
    const canvas = document.getElementById("stage");
    context = canvas.getContext("2d");

    document.addEventListener("keyup", onKeyUp, false);
    document.addEventListener("keydown", onKeyDown, false);


    window.requestAnimationFrame(render);

};

