#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIM"÷�Ʒ�"NOR, ({"Yueliang"}));
        set("nickname",HIM"�������š�"HIW+BLINK"����"NOR+HIR"��"HIG"��"HIB"��"HIY"Ů"NOR);
	set("gender", "Ů��");
	set("age", 25);
	set("per",31);
	set("long",@LONG
�������������Ȼ�Ĺ��񹦣����絶����������������������������Ƥ���׻��ס���
����������������ǳЦ��������״�ķ��١����̵����Σ�׺���������ʿ������̤��С
��ѥ�������·�����Ů���಻����ˡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
