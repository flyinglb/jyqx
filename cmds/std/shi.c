// poem.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
//	string arg;
 string *color = ({
RED,
HIR,
GRN,
HIG,
YEL,
HIY,
BLU,
HIB,
MAG,
HIM,
CYN,
HIC,
WHT,
HIW,
                });
	string *poem = ({
"����һ���ƣ����������ס�"NOR,
"���޲ʷ�˫����������Ϭһ��ͨ��"NOR,
"ͣ��Ͷ�粻��ʳ���ν��Ĺ���ãȻ��"NOR,
"�鵶��ˮˮ�������ٱ��������"NOR,
"ʮ��ĥһ����˪��δ���ԡ����հ��ʾ���˭�в�ƽ�£�"NOR,
"ʮ��Ϊ����������δ������"NOR,
"���粻��ʶ��������������"NOR,
"���������ƺ�֮ˮ���������������������ء�"NOR,
"�������ѻ����ݣ��������¶��Ũ��"NOR,
"����������໶�����þ�����Ц����"NOR,
"����Ϸ��Σ�����գ����֮�ѣ����������졣"NOR,
"���³���ɽ����ã�ƺ��䡣"NOR,
"������������ȥ���������Ⱨ������"NOR,
"����һЦ��鲭��ңָ��¥��檼ҡ�"NOR,
"����Ѱ�ɲ���Զ��һ��������ɽ�Ρ�"NOR,
"���ܴ�ü������Ȩ��ʹ�Ҳ��ÿ����ա�"NOR,
"һ֦����¶���㣬������ɽ���ϳ���"NOR,
                });
	

//    	if( !this_object()->id(arg) ) return 0;
    	if( me->is_busy() )
        		return notify_fail("������æ���أ���������������ʫ...\n");
   	if( me->is_fighting() )
        		return notify_fail("̫�����˰ɣ����ʱ����ʫ...\n");
/*	
	if( (int)me->query_skill("literate",1)<100 )
		return notify_fail("������ʫ��ҡͷ���Եغ��˼��䣬����û������ɶ��˼��\n");
	if( (int)me->query_skill("literate",1)>140 )
		return notify_fail("�������ַ����Ѿ��������裬�Ȿ�鲻�����㳤�����١�\n");

	sen_cost = 20 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")+1;
	me->improve_skill("literate", gain);
*/
        message_vision("$N����������" + color[random(sizeof(color))] + poem[random(sizeof(poem))] + "\n", me);
		
	return 1;
}

