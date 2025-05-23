// { dg-do compile { target comdat_group } }
// Force off function sections
// Force on exceptions
// { dg-options "-fno-function-sections -fexceptions" }
// PR middle-end/119507


inline int comdat() { try { throw 1; } catch (int) { return 1; } return 0; }
int another_func_with_exception() { try { throw 1; } catch (int) { return 1; } return 0; }
inline int comdat1() { try { throw 1; } catch (int) { return 1; } return 0; }
int foo() { return comdat() + comdat1(); }

// Make sure the gcc puts the exception table for both comdat and comdat1 in their own section
// { dg-final { scan-assembler-times ".section\[\t \]\[^\n\]*.gcc_except_table._Z6comdatv" 1 } }
// { dg-final { scan-assembler-times ".section\[\t \]\[^\n\]*.gcc_except_table._Z7comdat1v" 1 } }
// There should be 3 exception tables, 
// { dg-final { scan-assembler-times ".section\[\t \]\[^\n\]*.gcc_except_table" 3 } }
