
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"����"NOR,({"Qqqqq"}));
//      set("nickname", HIW NOR);
	set("gender", "����");
        set("age", 30);
	set("long", 
                "�����½�ӹȺ����II���������֮һ��Ҳ������ʵ����ң�\n"
                "��Ȼ�����������죬��������и��Ŭ��������Ҳ����������\n"
                "����֮�С�Ϊ�˳Ͽ���ֱ������С�ڣ����ڰ������ˡ�\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
