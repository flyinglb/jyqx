#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�ưټ�"NOR, ({"Robin"}));
	set("nickname",HIY"�ؼ��󱿵�"NOR);
	set("gender", "����");
	set("age", 35);
	set("per",29);
	set("long",@LONG 
������ĩ���������������������֮���ӣ������ս�Һ��
ʶ�䵱������ѧ�䣬Ϊ�䵱�ڼҵմ����С��ڼ�ȭ����������ȭ
ʮ�ν�������ѧ��������Ӻ������ڱ����뽭�ϸʷ�ز��ơ���
������������������ڸ�ѧʿ��Ϊ����ʷ��׫����֮һ����ΪѰ
�����պ��֪������ɽҰ�����˲�֪���٣�����Ϊ���ɶ�ȥҲ��
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
