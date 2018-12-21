# dngin
A modular game engine intended for code-first game development.

## Installation

Start by downloading and installing `dngn` for your system.

| OS         | Stable                   | Bleeding Edge            |
|------------|--------------------------|--------------------------|
| Windows 10 | [dngn-x86-64-0101.msi]() | [dngn-x86-64-0200.msi]() |
| Linux      | [dngn-deb-0101.dpg]()    | [dngn-deb-0200.dpg]()    |
| Mac        | [dngn-darwin-0101.bin]() | [dngn-darwin-0200.bin]() |

Install packages for `dngn` include its command-line interface, `kpr`. When using an installation package, `kpr` is added to your environment's path.

## Creating a Project

Use `kpr` to initialize a project.

```
kpr init 3d my-project
```

The standard project directory structure is created for you and default packages required for game with 3D graphics are added.

```
my-project
  |- src
  |  |- main.js
  |- build
  |- doc
  |- dngn-packages
  |- Makefile
  |- package.json
  |- dngn.config.json
```

The default packages include everything needed to run a basic, top-down 3D game without physics simulations. You can see the packages and versions added in the `package.json` file.

```
{
  "name": "my-project",
  "version": "0.1.0",
  "description": "A sample 3D game.",
  "main": "src/main.js",
  "scripts": {
    "start": "dngn main.js",
    "build": "make"
  },
  "dependencies": {
    "rast4man": "^4.13.3",
    "oge-graph": "^5",
    "dngn-runner": "1.0.1"
  },
  "license": "MIT"
}
```

Packages listed in the `dependencies` section are installed int he `dngn-packages` directory.

## Building

Executing a build creates a fresh `build` directory. This directory is platform specific and shouldn't be added to version control.

```
kpr build
```

## Running the Game

Starting the project creates a running instance that hot reloads when changes are made in the `src` directory.

```
kpr start
```

When starting with the default 3D project, a window should appear showing the refresh rate and finite plane. In order to add player controls or dev controls for the camera, read "Controling the View".

You can stop a run by terminating the application with `CTL-C`.

## Adding Functionality

The game doesn't have much going on at the moment so lets add some functionality.

The `src/main.js` file is the starting point for defining behavior in the game. The default looks something like...

```javascript
import dngn

// Create a game object.
const game = dngn.createGame3D({
    name: "my-game",
    devtools: true
});

// Create a scene graph.
const scene = dngn.createScene3D();

// Add a plane, light, and camera to the scene.
scene.addGameObject(dngn.createShape('plane', {
    name: "floor",
    dimensions: [10, 10],
    position: [0, 0, 0]
}));
scene.addLight(dngn.createLightOmni({
    name: "main-light",
    position: [0, 0, 10]
}));
scene.addCamera(dngn.createCamera({
    name: "primary",
    position: [1, 1, 1]
}));

// Add the scene and set it active.
game.addScene(scene);
game.activateScene(scene);

// Run the game loop.
dngn.run();
```

We can add a new shape to the scene by putting it just after the creation of the plane. Adding this to `main.js` causes a box to appear in the reder window.

```javascript
scene.addGameObject(dng.createShape('cube', {
    name: "box",
    dimensions: [0.1, 0.1, 0.1],
    position: [0, 0, 0]
}));
```

## Adding Packages

Packages can be added to the game project when additional functionality is called for. Lets add a user control package and let the user control the main camera.

Install the user control package.

```
kpr install dngn-user-control --save
```

Any running game must be quit before the package can be installed.

Import `user-control` and assign control of the main camera to keys.

```javascript
import dngn
import userControl

// Create a game object.
const game = dngn.createGame3D({
    name: "my-game",
    devtools: true
});

// Create a scene graph.
const scene = dngn.createScene3D();

// Add a plane, light, and camera to the scene.
scene.addGameObject(dngn.createShape('plane', {
    name: "floor",
    dimensions: [10, 10],
    position: [0, 0, 0]
}));
scene.addLight(dngn.createLightOmni({
    name: "main-light",
    position: [0, 0, 10]
}));
scene.addCamera(dngn.createCamera({
    name: "primary",
    position: [1, 1, 1]
}));

// Add the scene and set it active.
game.addScene(scene);
game.activateScene(scene);

// Assign user controls to the main camera.
userControl.listen('a', 
    {action: "pan-left"}, 
    scene.getCamera("primary"));
userControl.listen('d', 
    {action: "pan-right"}, 
    scene.getCamera("primary"));
userControl.listen('w', 
    {action: "dolly-forward"}, 
    scene.getCamera("primary"));
userControl.listen('s', 
    {action: "dolly-back"}, 
    scene.getCamera("primary"));

// Run the game loop.
dngn.run();
```

Rebuild and restart the game.

```
dngn start
```
