// d/yanziwu/npc/susu.c

inherit NPC;

void greeting(object);
void init();
void serve_tea(object);


void create()
{
        set_name("����", ({"susu", "su"}) );
        set("nickname", "�Ų�Ѿ��");
        set("gender", "Ů��" );
        set("age", 14+random(3));
        set("long",
          "���Ǹ������䲻���СѾ�ߣ������ɵ��·�Ҳ�ڲ�ס�����緢�������塣\n"
          "һ���������ɣ������������ݡ���������΢ʾ�⣬���ȥ�Ӳ赹ˮ��\n");
        set("attitude", "friendly");
        set("shen_type", 1);

        set("str", 20);
        set("int", 28);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

        set("combat_exp", 1000+random(800));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/cdamage", 3);


        setup();

}

void init()
{
        object ob;

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        say("����Ц������˵������λ" + RANK_D->query_respect(ob)
             + "����������" + "����͸����ϲ衣\n");
}


void serve_tea(object who)
{
         object obn;
        object room;

        if( !who || environment(who) != environment() ) return;

        if( !who->query_temp("marks/sit") ) return;

        if( !objectp(room = environment()) ) return;

        obn = new("/d/yanziwu/obj/cha");
        obn->move(room);
        message_vision("�����ó�һ��С���������һ����Ũ�ı��ݴ���\n",who);

        obn = new("/d/yanziwu/obj/gao");
        obn->move(room);
        message_vision("�����ó�һ�����µ���ɫ���ģ��������ϣ�\n", who);

        return;
}
