// function towerOfHanoi(n, from, to, aux) {
//   if (n == 1) {
//     // printf("Move %c to %c\n", from, to);
//     // Move {from} to {to}
//     return;
//   }
//   towerOfHanoi(n - 1, from, aux, to);
//   // printf("Move %c to %c\n", from, to);
//   // Move {from} to {to}
//   towerOfHanoi(n - 1, aux, to, from);
// }
const canvas = document.querySelector("canvas");
canvas.width = innerWidth - 10;
canvas.height = innerHeight - 100;

const ctx = canvas.getContext("2d");

const TOWER_HEIGHT = 3;

const randomRGB = () =>
  "rgb(" +
  Math.round(Math.random() * 255) +
  ", " +
  Math.round(Math.random() * 255) +
  ", " +
  Math.round(Math.random() * 255) +
  ")";

const colWidth = canvas.width / 3;

class Disk {
  constructor(size, stack, h, color) {
    this.size = size;
    this.stack = stack;
    this.h = h;
    this.color = color;
    this.coords = {
      x: 0,
      y: 0,
    };
    this.targetCoords = {
      x: 0,
      y: 0,
    };
  }
  move(newStack) {
    this.targetCoords.x = colWidth * newStack + colWidth;
  }
  draw() {
    ctx.fillStyle = randomRGB();
    ctx.rect;
  }
}

const disks = Array.from(
  { length: TOWER_HEIGHT },
  (_, idx) => new Disk(idx + 1, 0, TOWER_HEIGHT - idx - 1, randomRGB())
);

function animate() {
  requestAnimationFrame(animate);
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  disks.forEach((disk) => {
    disk.draw();
  });
}

animate();
