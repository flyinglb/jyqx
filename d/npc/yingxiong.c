#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"Ӣ��"NOR, ({"Yingxiong"}));
        set("nickname",HIC"��"HIR + BLINK+"ѪӰ��"+NOR+HIC"��"+HIM+"��������"+HIW+"�������"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",30);
	set("long",@LONG
�������ڽ�ӹȺ��MUD�����Ծ�����ˣ���������������ˡ����ֳ�һ��
����ɫ��Ӣ�۽��۳ҽ�����֮�������Լ��İ�ᡸ����ɽׯ������һ
����ң���ڣ������Ի�Ծ�ڽ����ϣ���Ҳ�ǡ�����ɽׯ���Ĵ�ʼ�ˡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
