// npc: /d/city/npc/wei.c
// Dec.12.1997 by Venus
#include <ansi.h>;
inherit NPC;
void create()
{
        set_name("Τ����", ({ "wei chunfang", "chunfang", "wei" }) );
        set("gender", "Ů��" );
        set("title", "����Ժ�ϰ���");
//      set("nickname", "¹����");
        set("age", 42);
        set("long",
            "Τ�����ǵ���¹������컨���ܶ���ΤС�����������"
            "����ϣ��������̴档\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 20);
        set_skill("force", 20);
        set_skill("dodge", 35);

        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "name"   : "�����Ҿ���Τ������",
            "ΤС��" : "�����ҵĹԶ��ӣ����þ����㡣",
            "����Ժ" : "��������Ժ�������ݳ���ͷһ�ݵ�������ȥ����",
            "here"   : "��������Ժ�������ݳ���ͷһ�ݵ�������ȥ����",
        ]) );

        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                "Τ���������˵�������������ұ��µúܣ�ÿ���кü������ˡ�\n",
                "Τ����ŭ������������裬Ҫ����ɲ����ë���ӵ�����Ժ����������
��ɨ�����˳�ȥ��\n",
                "Τ��������˵������һ˫�۾���߯�����ģ������Ǹ����\n",
        }) );
        carry_object("/d/city/obj/flower_shoe")->wear();

        carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_sell", "sell");
}

void greeting(object me)
{
    command("look " + me->query("id"));
/*

    if (me->query("gender")=="����") {
       command("say �㵱��������������������裬���������ɲػض��ӣ�
���ǲ���̫�࣡\n");
       command("kick " + me->query("id"));
       message("vision", me->name() +"��Τ����һ���߳����⡣\n",
                environment(me), ({me}));
       me->move("/d/city/nandajie2");
       message("vision", me->name() +
"���˴�����Ժ�����˳������Ե��ڵ��ϣ��ĵ�����������\n",environment(me), ({me}));

    }
*/
//  else {
    if (me->query("class") =="bonze") {
       command("say �ϣ�" + RANK_D->query_respect(me)
                +"Ҳ�������������Ժ����");
       command("say �뵱���ҽӹ�һ������������ϴ�ǰһ��Ҫ���һ�����
�����Ӿ͹�����������ҡ�");
    }
    if (me->query("gender")=="Ů��") {
       command("say ��ѽ�������´����Ҳ��Ҥ�ӣ��ɺ���ͬ��");
       command("sigh");
       command("say ��ϧ�Ҷ��Ӳ��ڣ���Ȼ�����ź��㡣");
    }
    else { command("say ¥��¥�µĹ����ǣ��������ˣ�");
    }
    return ;
}

int do_sell(string arg)
{
	object ob, myenv;
	int value;
	
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!userp(ob))
		return notify_fail("����ֻ���ˡ���������Ҫ����ʲô������\n");
	if( query_ip_name(this_player()) == query_ip_name(ob))
		return notify_fail("�Լ����Լ���ʵ���Ƿ����е��ˡ�\n");
	if (ob->query_condition("prostitute") > 1)
		return notify_fail("�����Ѿ�����������ˡ��㻹����ƭǮ��\n");

	ob->set("value", ob->query("per") * 800);
	command("rumor "+ob->query("name")+"������������Ժ�ˣ����಻�٣�����" +
		CHINESE_D->chinese_number(ob->query("value")) + "��ͭ���ġ�\n");

	message_vision("$N��" + ob->query("name") + "����Τ������\n", this_player());
	MONEY_D->pay_player(this_player(), value * 70 / 100);
	myenv = environment (this_player());
	tell_room(myenv,"Τ�������Ĵ�Ц������Ҫ�����ˡ�\n");
	ob->move("/d/city/lichunyuan2");
	ob->set("startroom","/d/city/lichunyuan2");
	ob->apply_condition("prostitute", 50);
	ob->set_temp("selled");
	ob->set("class", "prostitute");
	return 1;
}

