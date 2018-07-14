int
main()
{
    int phone_digits[] = { 3, 3, 1, 2, 9, 1, 5 };
    char phone_chars[] = "331-2915";
    int i = 3;
    int * ip = &i;
    int * pn;
    char * ps = phone_chars;

    pn = phone_digits;

//     value01 = phone_digits[i];
//
//     value02 = phone_chars[i];
//
//     value03 = pn;
//
//     value04 = phone_digits;
//
//     value05 = pn[i];
//
//     value06 = &i;
//
//     value07 = *ip;
//
//     value08 = ps;
//
//     value09 = phone_chars;
//
//     value10 = *phone_digits;
//
//     value11 = *phone_chars;
//
//     value12 = &ip;
//
//     value13 = &pn;
//
//     value14 = &ps;

      int** value15 = *&i;

//     value16 = *&ip;
//
//     value17 = *&ps;
//
//     value18 = &phone_digits[0];
//
//     value19 = &phone_digits[i];
//
//     value20 = &phone_chars[0];
//
//     value21 = &phone_chars[i];
}
