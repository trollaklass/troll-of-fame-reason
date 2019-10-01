# Troll of Fame - ReasonML training

This project use [ReasonML](https://reasonml.github.io) with [esy](https://esy.sh/) workflow and [Dune](https://github.com/ocaml/dune) build system.

## Getting started

- Install esy : `npm install -g esy`
- Install dependencies : `esy`
- Work with your IDE (VSCode - recommended, VIM, Emacs ) : `esy x [MY_IDE]` ie `esy x code .`
- Run compiled executable : `esy x Fame`
- Run tests : `esy x Runner`

Nota Bene : If you're using VS Code, you should install [OCaml and Reason IDE](https://marketplace.visualstudio.com/items?itemName=freebroccolo.reasonml) and enable the parameter _Reason › Codelens: Enabled_

## Once upon a time ...

The King of the Trolls Gnonpom coded the **Troll of Fame** : a wonderfull application that would help Trolls to learn numbers when they are hunting.
Gnonpom was a hard skilled Test Driven Developer king who just released **ToF** when all tests passed Green.

Sadly he was shooted by a disgusting Elf.

Here come a new King, Hurrah for the great Troll Aklass!

This time it's decided, the elf hunting contest is launched!

At the end of each battle, the trolls want to compare the number and attributes of the slain elves. And with **ToF** it will be easy ... maybe.

## Excercices

### Work with legacy code

You inherit an application that seems to work fine. Run `esy x Runner` (•̀ᴗ•́)و ̑̑

Read [Elf_test.re](./test/lib/Elf_test.re) and [Troll_test.re](./test/lib/Troll_test.re) as a first specification of the software.

Now uncomment the content of [Elf_prop.re](./test/lib/Elf_prop.re) and run tests again `esy x Runner`... Ooops seems that our unit tests was not so complete. (╥﹏╥)

We will try to improve the quality of _Troll of Frame_ thanks to Property Based Testing

### Property testing

Property Based Testing (a.k.a. PBT) is about generating tests instead of manually writing them. Unlike unit tests where you know what goes in and what comes out (a.k.a. oracle tests), you assess properties that should always be true. The PBT library checks for arbitrary inputs that the property is true.

In ReasonML, we use `qcheck-rely` library to write and run Property Based tests.

#### Step 1 - Configuration and Invariance

#### Step 2 - Inverse

#### Step 3 - Analogy

#### Step 4 - Idempotence

#### [Bonus] Step 5 - Metamorphism
