#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"СҶ"NOR, ({"Yedou"}));
        set("nickname",MAG"ʮ��ɱһ�ˣ�ǧ�ﲻ����"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
�����½�ӹȺϺ���ĵڶ���Ԫ�ϣ�Ϊ�˺Ͱ����ס���Ȼ������
�ò��Ǻܿ죬������������ȴ�ǿ��ԡ���ȻҲ�����ɹ�һЩ
С͵С�����£�ȴ����������������ۡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
