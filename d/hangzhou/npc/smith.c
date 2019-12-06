// smith.c

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("����", ({ "tiejiang", "smith" }));
        set("shen_type", 1);

        set("gender", "����" );
        set("age", 33);
        set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");

        set("combat_exp", 400);
        set("attitude", "friendly");
        set("vendor_goods",({
                   "/d/city/obj/changjian",
                   "/d/city/obj/hammer",
                   "/d/city2/obj/tudao",
                   "/d/xingxiu/obj/tiegun",
                   "/d/city/obj/gangdao",
        }));
        setup();

        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
         object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say("����˵������ӭ��λ"+RANK_D->query_respect(ob)+"���٣������ιۡ�\n\n");
}
