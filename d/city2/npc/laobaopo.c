// lapbaopo.c
inherit NPC;

void create()
{
        set_name("�����", ({ "laobao po", "laobao", "po" }) );
        set("gender", "Ů��" );
	set("title", "����Ժ�ϰ���");
        set("age", 42);
        set("long", 
            "\n�����������������ϣ����Է����ȴ棬ֻ�������ϵķ�̫���ˡ�\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
	set("no_get", "1");
        set("shen_type", -1);

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
            "����Ժ" : "��������Ժ���Ǳ�������ͷһ�ݵ�������ȥ����",
       ]) );

        setup();
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
}

void greeting(object me)
{
    command("look " + me->query("id"));

    if (me->query("gender")=="����") {
       command("say �㵱��������������������裬���������ɲػض��ӣ����ǲ��ź�̫�࣡");
       command("kick " + me->query("id"));
       message("vision", me->name() +"�������һ���߳����⡣\n",
                environment(me), ({me}));
       me->move("/d/city2/dongcha2");
       message("vision", me->name() +"���˴�����Ժ�����˳������Ե��ڵ��ϣ��ĵ�����������\n", 
                environment(me), ({me}));

    }
    else {
    if (me->query("class") =="bonze") {
       command("say �ϣ�" + RANK_D->query_respect(me) 
                +"Ҳ�������������Ժ����");
       command("say �뵱���ҽӹ�һ������������ϴ�ǰһ��Ҫ���һ����������Ӿ͹�����������ҡ�");
    }
    if (me->query("gender")=="Ů��") {
       command("say ��ѽ�������´����Ҳ��Ҥ�ӣ��ɺ���ͳ��");
       command("sigh");
       command("say ��ϧ�Ҷ��Ӳ��ڣ���Ȼ�����ź��㡣");
    }
    command("say ¥��¥�µĹ����ǣ��������ˣ�");
    }
    return ;
}

