// smith.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("������", ({ "feng", "smith" }) );
	set("gender", "����" );
	set("age", 53);
	set("long", 
"���������ǳ��������������������ˣ�˫�۱��̻�޹���ֺ���ϸ��\n"
"���Ȳзϣ������³���һ�����ȡ�\n");
	set("combat_exp", 50000);

        set("str", 24);
        set("dex", 17);
        set("con", 28);
        set("int", 27);
	set("shen_type", 1);

        set("attitude", "friendly");
        set_skill("dodge", 70);
	set_skill("hammer", 40);
	set_skill("parry", 60);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set("vendor_goods", ({
                __DIR__"obj/hammer",
        }));
//        set("chat_chance", 50);
//	set("chat_msg_combat", (: add_hammer :));
	set("inquiry", ([
		"name": "С���շ룬�����˶����ҷ�������",
		"here": "������С�˺��ڵ����ӣ�С�˾�ס����ߵ����ӡ�",
		"��ͷ": "��ͷ... ��Ǹ����ͷ�Ѿ�������...",
		"����": "������С������������������ã�һ��ֻҪ������Ǯ��",
		"��"  : "Ŷ�����Ǹ���ɽ�������Ŵ�ģ�С�����������£�����û�˷��ǿ������\n"
		"�ţ�������ǰ��������ͽ��ɽȥ�ˣ���֪ʲ��ʱ��Ż�������ȡ����",
		"ȡ��": "С��һ��Ҫ���������ŵ����Ų��ܸ�����",
		"��Ĭ��" : "�������������С���Ѿ��þ�û����������...",
		"���Ŷݼ�" : "�Ƕ���Сʱ��ѧ�ģ�ƽʱû�½���ư��ˡ�",
	]) );
	setup();
        add_money("coin", 50);
	carry_object(__DIR__"obj/hothammer")->wield();
}
void init()
{
        ::init();
        add_action("do_buy", "buy");

}

int accept_object(object who, object ob)
{
	object sword;
	sword = new(__DIR__"obj/youlong");
        if ((string)ob->query("id")=="hand letter") {
              if(!query("yl_trigger")) {
		say(
"������˵������ѽ��䲻���ۣ���Ҳ��С�˵���Ѫ������Ե��������š�\n"
"��������" + sword->query("name") + "������" + who->query("name") + "��\n");
		sword->move(who);
                set("yl_trigger", 1);
              }
           else say("��������Ҳ��̧��˵����Ҫ���Լ���ȥ�á�\n");
        call_out("destroy", 1, ob);
	return 1;
	}
	return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
// void add_hammer()
// {
//	if (this_object()->is_fighting() )
//             carry_object(__DIR__"obj/hammer")->wield();
// }

