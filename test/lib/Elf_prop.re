open Framework;
open QCheckRely;
open Generator.Fantasy;
open Lib.Elf;

let {describe} = extendDescribe(QCheckRely.Matchers.matchers);

/* Porperties Based Tests */
describe("Elf Invariance", ({test}) => {
  test("Elf value should always be positive", ({expect})
    => {
      QCheck.Test.make(
        ~count=1000,
        ~name="elf value should always be positive",
        elf_arbitrary,
        elf =>
        value(elf) > 0
      )
      |> expect.ext.qCheckTest;
      ();
    })
    /* test("The value of a High elf must be an even number", ({expect}) => {
         QCheck.Test.make(
           ~count=1000,
           ~name="The value of a High elf must be an even number",
           elf_high_arbitrary,
           elf =>
           value(elf) mod 2 === 0
         )
         |> expect.ext.qCheckTest;
         ();
       }); */
});