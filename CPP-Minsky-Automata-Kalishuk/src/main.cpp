
/*
# COPY REG A TO REG B USING REG C, AND CLEAR B

i-1 : DEC_JNZ B, i-1, i		-- clear B
i	: DEC_JNZ A, i+1, i+3	-- remove A, raise B and C
i+1 : INC_JMP B, i+2
i+2 : INC_JMP C, i
i+3 : DEC_JNZ B, i+4, i+5	-- remove B, raise A back
i+4 : INC_JMP A, i+3
i+5 : END
*/


#include "../headers/custom.hpp"
#include "../headers/compiler.hpp"
using namespace std;

MinskyAutomata* compiled_src_to_auto(CompiledSource* cmp){
	MinskyAutomata *new_automaton = new MinskyAutomata(cmp->reg_amt);
	Program *new_program = new Program;
	new_program->read_append_instructions(cmp->instructions);
	for (int i = 0; i < cmp->reg_list.size(); i++){
		new_automaton->set_n(i, cmp->reg_list[i]);
	}
	new_automaton->add_program(*new_program);
	return new_automaton;
}


int main(int argc, char **argv){
	CompiledSource* cmp = 
		parse_file_to_instructions(
		(char *)"CPP-Minsky-Automata\\minsky_machine_programs\\test.txt");
	MinskyAutomata* aut = compiled_src_to_auto(cmp);
	aut->exec_program(0);
	vector<int> v = aut->get_regs();
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << ' ';
	}
	return 0;
}