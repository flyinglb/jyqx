#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"����Ӱ"NOR, ({"Szb"}));
	set("nickname",HIG"��"HIR+BLINK"ѪӰ��"NOR+HIC"��"HIM"������"HIG"ԧ"HIY"�콣"NOR);
	set("gender", "����");
	set("age", 32);
	set("per",26);
	set("long",@LONG
�����ǡ�ѪӰ�š��Ĵ�ʼ�ˣ�ϲ�����������죬���䡣����Ϊmud��Ӧ
���Ǹ����һ���书�ڶ�����һ��ֻ��ԧ�첻�������ң���Ϊ�������
��Ƿ���(tianxiawudi)����Ը�����һֱ�ڱ�mud������Ϸ��ȥ��
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
