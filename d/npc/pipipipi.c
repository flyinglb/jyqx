#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�������"NOR, ({"Pipipipi"}));
        set("nickname",HIY"��"HIR"��ħ��"HIY"��"BLK"ʹ�� "HIR"��"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
              ���˼�  ���Ǻ���  ֱ����������
              ���ϵر�˫�ɿ�  �ϳἸ�غ���
              ����Ȥ  ����  ���и��гն�Ů
              ��Ӧ����  ���������  ǧɽĻ��  ֻӰΪ˭ȥ
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
