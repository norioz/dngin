#pragma once

/*
Several different concepts of objects in physics :
static - InfMass objects.Could move via gameplay, but not using any physical laws.
Rigid body - A larger object represented as a single newtownian object / particle.
Spring - A physically constrained relationship between two rigid bodies (using hooke's law)
    Soft body - A network spring connected rigid bodies particles (typically 3 types: attractor, repulsor and stabilizers)
    Skeletal - or a Ragdoll, is a tree of rigid bodies and springs with constraints that is sometimes 'powered.'
    Fluid / Gas - A volumetric simulation layer based on navier - stokes.

    They can be unified under volumetric or particle based solutions, though they are impractical.

We'll focus on rigidbody dynamics for now-- we want to have working rigid bodies so that we can use them in collision resolution.

Typically we use reverse Euler integration for its computational efficiency and elegance.

F: Aggregation of forces that have occured during the reference frame.
I: Aggregation of impules that have occured during the reference frame.
A: Acceleration
V: Velocity
P: Position
dt: Delta Time, duration of the reference frame.
M: Mass
D: Drag

A  = F/M
`V = (V - V * D + A) * dt + I/M
`P = P + `V * dt

A  = F/M
Newton's force equation for instantaneous acceleration. 
Conceptually these are 'continuous' forces that apply continuously over time (gravity).
Sudden bursts of velocity (jumping) are done through impulses instead. Though you may want
an effect that applies a force of acceleration over a period of time (So you get the sensation of jerk).

V*D Is the drag component.
A dampening force that is based on the velocity. V - V * D * dt (as above), will move V toward 0
over time. Drag is a bullshit concept in physics, but it's unhealthy for objects to not slow down.

A*dt integrates the acceleration into velocity.

I/M is the impulse, or instantaneous velocity, over the object's mass. A sudden injection of velocity
is experienced as a burst of speed (like a jump).

The last line is straightforward euler integration of velocity into position.(edited)
Typically the Rigidbody owns all the physics state, but position is owned by a Transform
so our Rigidbody, for now, could look something like this:

Rigidbody {
    float mass, drag;

    // Acceleration is calculated from force. We don't need to store it.
    // Force/Impulse should be private, but manipulating velocity directly is valid.
    vec velocity, force, impulse;

    // Allows other objects to apply their forces to this one.
    void AddForce (vec val);
    void AddImpulse (vec val);

    // Performs integration and resets force/impulse for the next frame (zeroes them out). Return the new position.
    // In the future, rotation can be updated here as well, but inertia tensors, torque, and applying force to positions on the object add a lot of complexity.
    // The interface would change here quite a bit.
    vec integrate (vec pos, float dt);
};
*/