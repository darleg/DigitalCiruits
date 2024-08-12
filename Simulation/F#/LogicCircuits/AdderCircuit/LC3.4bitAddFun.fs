// Learn more about F# at http://docs.microsoft.com/dotnet/fsharp
// See the 'F# Tutorial' project for more help.

// Define a function to construct a message to print
let from whom =
    sprintf "from %s" whom

[<EntryPoint>]
let main argv =
    let message = from "F# 4bitAddFun" // Call the function
    printfn "4bi Adder Function Simulator %s" message
    0 // return an integer exit code

    let NOT a = not a
    let AND a b = a && b
    let OR a b = a || b
    let XOR a b = a <> b
    let NAND a b = AND a b |> NOT
    let NOR a b = OR a b |> NOT
    let NXOR a b = XOR a b |> NOT
        
        //Half Adder
    let HA a b =
        let s = XOR a b // one xor gate
        let c = AND a b // one and gate
        (s, c)          // retrims sum and carry
            
        //Full Adder
    let FA a b cin = 
        let (s1, c1) = HA a b     // first half adder
        let (sum, c2) = HA s1 cin // second half adder
        let cout = OR c1 c2       // or gate for the 2 carry out
        (sum, cout)



    let HexAdder (areg : bool array, breg : bool array) =
        let Cin3 : bool = false

        let (Sreg3, Cout3) = FA areg.[3] breg.[3] Cin3
        let Cin2 = Cout3
        let (Sreg2, Cout2) = FA areg.[2] breg.[2] Cin2
        let Cin1 = Cout2
        let (Sreg1, Cout1) = FA areg.[1] breg.[1] Cin1
        let Cin0 = Cout1
        let (Sreg0, Cout0) = FA areg.[0] breg.[0] Cin0

        let Sreg : bool array = [| Sreg0; Sreg1; Sreg2; Sreg3 |]
        (Sreg, Cout0)

    let Areg : bool array = [| true; true; true; false |]
    let Breg : bool array = [| false; true; false; true |]

    let (Sreg, Cout0) = HexAdder (Areg, Breg)

    printfn("Areg is %A")Areg
    printfn("Breg is %A")Breg
    printfn("Sum  is %A")Sreg
    printfn("Carry out is %b")Cout0

    0 // return an integer exit code
