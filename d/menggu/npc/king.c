#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�ɼ�˼��", ({ "chengjisihan", "king"}) );
        set("title", HIC"һ���콾"NOR);
        set("gender", "����");
        set("age", 53);
        set("per", 25);
        set("long",
"����������ʷ��ӵ�������������ľ������޵е��ɹ����Ｘ��̤��ŷ�Ǵ�½��\n");
        set("combat_exp", 500000);
        set("attitude", "piece");
	set("chat_msg", ({
		"\n�ɼ�˼����ü����������ģ��ս������Щ�Խ�����������Ҫ�����ˡ�\n"
		"\n�ɼ�˼����Ц���������ڽ�����������檳�Ⱥ���������ã��Թ�˭�ܱȵ����ң�\n"
		"\n�ɼ�˼����̾�����þ�û���������ˣ����ݳ��ͷ�������ˡ�\n"
	}) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 30);
}
