
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"����"NOR,({"Pos"}));
        set("nickname", HIW"�� "HIR"��Ѫɽׯ"HIW" ��"HIC"��ׯ�� "BLINK"����"HIY"ͭƤ"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
                "�׻�˵�������򲻴������ǰ�������ȴ����ô��ȷ��\n"
                "��������ʵķ����������ٶ��ڶ�ʱ���������ڸ���֮�С�\n"
                "ֻ��ƽʱȴ������Ц����������Ҳѵ���ÿ���˻������ˡ�\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
