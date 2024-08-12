// Learn more about F# at http://docs.microsoft.com/dotnet/fsharp
// See the 'F# Tutorial' project for more help.

// Define a function to construct a message to print
let from whom =
    sprintf "from %s" whom

[<EntryPoint>]
let main argv =
    let message = from "F# LogicGate3" 
    printfn "F# Logic Gates Table %s" message
    
    let NOT a = not a
    let AND a b = a && b
    let OR a b = a || b
    let XOR a b = a <> b
    let NAND a b = AND a b |> NOT
    let NOR a b = OR a b |> NOT
    let NXOR a b = XOR a b |> NOT

    let a = true
    let b = true

    printf "NOT Truth Table \n"
    printf  "    A       Y \n"
    printfn "   true %b" (NOT true)
    printfn "   false %b\n" (NOT false)
    
    
    printf "AND Truth Table \n"
    printf  "    A   B       Y  \n"
    printfn " false false  %b"   (AND false false)
    printfn " false true   %b"   (AND false true)
    printfn " true  false  %b"   (AND true false)
    printfn " true  true   %b\n" (AND true true)

    printf "OR truth Table \n"
    printf  "    A   B       Y  \n"
    printfn " false false  %b"   (OR false false)
    printfn " false true   %b"   (OR false true)
    printfn " true  false  %b"   (OR true false)
    printfn " true  true   %b\n" (OR true true)
    
    printf "XOR truth Table \n"
    printf  "    A   B       Y  \n"
    printfn " false false  %b"   (XOR false false)
    printfn " false true   %b"   (XOR false true)
    printfn " true  false  %b"   (XOR true false)
    printfn " true  true   %b\n" (XOR true true)

    printf "NAND truth Table \n"
    printf  "    A   B       Y  \n"
    printfn " false false  %b"   (NAND false false)
    printfn " false true   %b"   (NAND false true)
    printfn " true  false  %b"   (NAND true false)
    printfn " true  true   %b\n" (NAND true true)

    printf "NOR truth Table \n"
    printf  "    A   B       Y  \n"
    printfn " false false  %b"   (NOR false false)
    printfn " false true   %b"   (NOR false true)
    printfn " true  false  %b"   (NOR true false)
    printfn " true  true   %b\n" (NOR true true)

    printf "NXOR truth Table \n"
    printf  "    A   B       Y  \n"
    printfn " false false  %b"   (NXOR false false)
    printfn " false true   %b"   (NXOR false true)
    printfn " true  false  %b"   (NXOR true false)
    printfn " true  true   %b\n" (NXOR true true)



    0 // return an integer exit code
