#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"��ѧϰ"NOR, ({"Lovenow"}));
	set("nickname",HIR"��"+HIC+"�Կ�"+HIW+"����"+BLINK+HIM+"ռ����"+NOR+HIR+"��"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
��������������
�� ����Զ�����ҵ�����   ��
�� ���ܲ������˲εĲ��� ��
��������������
���ǽ�ӹȺ������ɳ��ǳ������һ�����֣������������������̶����������������
ʵս���顣�������Ѿ����ڰ�����״̬�ˣ�����ֻҪ�л��ᣬ�����ǻ᳣����˵ġ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
