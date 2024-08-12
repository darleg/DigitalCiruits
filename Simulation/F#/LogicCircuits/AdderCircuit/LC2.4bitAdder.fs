// Learn more about F# at http://docs.microsoft.com/dotnet/fsharp
// See the 'F# Tutorial' project for more help.

// Define a function to construct a message to print
let from whom =
    sprintf "from %s" whom

[<EntryPoint>]
let main argv =
    let message = from "F# 4bitAdder" // Call the function
    printfn "4bit Adder Simulator %s" message

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


    let Areg : bool array = [| true; false; false; false |]
    let Breg : bool array = [| false; true; false; false |]

    printfn("Areg is %A")Areg
    printfn("Breg is %A")Breg

    let Cin : bool array = Array.create 4 false
    let Cout : bool array = Array.create 4 false

    let (Sreg3, Cout3) = FA Areg.[3] Breg.[3] Cin.[3]
    let Cin2 = Cout3
    let (Sreg2, Cout2) = FA Areg.[2] Breg.[2] Cin.[2]
    let Cin1 = Cout2
    let (Sreg1, Cout1) = FA Areg.[1] Breg.[1] Cin.[1]
    let Cin0 = Cout1
    let (Sreg0, Cout0) = FA Areg.[0] Breg.[0] Cin.[0]

    let Sreg : bool array = [| Sreg0; Sreg1; Sreg2; Sreg3 |]
    
    printfn("Sum  is %A")Sreg
        

    0 // return an integer exit code
