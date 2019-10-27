open Lib;
open QCheck.Gen;

module type MFantasy = {
  let elf_arbitrary: QCheck.arbitrary(Lib.Elf.t);
  let elf_high_arbitrary: QCheck.arbitrary(Lib.Elf.t);
  let troll_arbitrary: QCheck.arbitrary(Lib.Troll.t);
  let troll_elf_arbitrary: QCheck.arbitrary((Lib.Troll.t, Lib.Elf.t));
  let troll_elf_int_arbitrary:
    QCheck.arbitrary((Lib.Troll.t, Lib.Elf.t, int));
  let troll_two_elves_arbitrary:
    QCheck.arbitrary((Lib.Troll.t, Lib.Elf.t, Lib.Elf.t));
};

module Fantasy: MFantasy = {
  /* Elf Generator */
  let elf_gen =
    Elf.(
      pair(
        oneofl([Swordsman, Archer, Warlock, Priest]),
        oneofl([HighElf, DarkElf]),
      )
      >|= (pair => from_pair(pair))
    );

  let elf_high_gen =
    Elf.(
      pair(oneofl([Swordsman, Archer, Warlock, Priest]), pure(HighElf))
      >|= (pair => from_pair(pair))
    );

  let elf_print = elf => Elf.show(elf) |> QCheck.Print.string;
  let elf_arbitrary = QCheck.make(~print=elf_print, elf_gen);

  let elf_high_arbitrary = QCheck.make(~print=elf_print, elf_high_gen);

  let name_gen = string(~gen=QCheck.Gen.printable);

  let kill_gen =
    pair(elf_gen, nat)
    >|= (
      pair => {
        let (key, value) = pair;
        Troll.Killed.update(
          key,
          Troll.optional_add(Some(value)),
          Troll.Killed.empty,
        );
      }
    );

  let killed_merger = (acc, v) => {
    Troll.Killed.merge(
      (k, x, y) =>
        switch (x, y) {
        | (Some(xo), Some(yo)) => Some(xo + yo)
        | (None, Some(_)) => y
        | (Some(_), None) => x
        | _ => None
        },
      acc,
      v,
    );
  };

  let list_killed_to_map_killed = kills =>
    List.fold_left(killed_merger, Troll.Killed.empty, kills);

  let troll_gen =
    pair(name_gen, QCheck.Gen.list(kill_gen))
    >|= (
      ((name, kills)) =>
        Troll.{name, kills: list_killed_to_map_killed(kills)}
    );
  let troll_print = troll => Troll.show(troll) |> QCheck.Print.string;

  let troll_arbitrary = QCheck.make(~print=troll_print, troll_gen);
  let troll_elf_arbitrary = QCheck.pair(troll_arbitrary, elf_arbitrary);
  let troll_elf_int_arbitrary =
    QCheck.triple(troll_arbitrary, elf_arbitrary, QCheck.small_nat);
  let troll_two_elves_arbitrary =
    QCheck.triple(troll_arbitrary, elf_arbitrary, elf_arbitrary);
};
