#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"��˪"NOR, ({"Lyz"}));
	set("nickname",HIG"Ů��"NOR);
	set("gender", "Ů��");
	set("age", 35);
	set("per",29);
	set("long",@LONG
����������Ȼ��Ծ����̶�е�һ����λ���������Ψһ��һ
λ���Ծ����������ưټҳ�Ϊ��ʦ�Ժ������ɾ��ǽ���������
�������ص����������ˡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
