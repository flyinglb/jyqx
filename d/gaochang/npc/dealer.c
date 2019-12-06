
// Jay 3/17/96
inherit NPC;
void create()
{
        set_name("��˹������", ({ "bosi dealer", "dealer" }));
        set("gender", "����");
        set("age", 40 + random(10));
        set("long", "һ�������Ĳ�˹�����ˡ��߱����۵�, ����������¶����թ��Ц�ݡ�\n");
        set("attitude", "friendly");
        set_max_encumbrance(10000000);
        set("combat_exp", 6000);
        set("shen_type", 1);
        set_skill("unarmed", 30);
        set_skill("blade", 40);
        set_skill("parry", 30);
        set_skill("dodge", 40);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 20);
        set("vendor_goods", ({
                __DIR__"obj/hamigua",
                __DIR__"obj/yangpi",
                __DIR__"obj/langpi",
//                __DIR__"obj/xuecan",
        }) );
        set("inquiry", ([
                "����" : "��ֻ�չ����ܹ�, ��Ƥ, ��Ƥ, ѩ��",
                "�չ�" : "��ֻ�չ����ܹ�, ��Ƥ, ��Ƥ, ѩ��",
                "��Ʒ" : "��ֻ�չ����ܹ�, ��Ƥ, ��Ƥ, ѩ��",
                "����" : "��ֻ�չ����ܹ�, ��Ƥ, ��Ƥ, ѩ��",
        ]) );
        set("no_put",1);
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"��˹�����˶����թ�ؼ���һ���۾���\n",
        }) );
        carry_object(__DIR__"obj/wandao")->wield();
        carry_object(__DIR__"obj/changpao")->wear();
        add_money("silver", 20);
}
void init()
{
        object ob;
        ::init();
        add_action("do_sell", "sell");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
                  say("��˹�����˶���˵���������ɰͣ��º�Ĭ�����ذ����� ��û��������\n");
}
string is_vendor_good(string arg)
{
        string *goods,*all_id;
        int i,j;
        if (goods = query("vendor_goods")) 
        for (i = 0; i < sizeof(goods); i++){
            if (!all_id=goods[i]->parse_command_id_list())
                return "";
            if (goods[i]->query("name")==arg)
                return goods[i];
            for (j=0;j<sizeof(all_id);j++)
                if (all_id[j]==arg)
                    return goods[i];
        }
        return "";
}

int do_sell(string arg)
{
        object ob;
        int value;
         if (!living(this_object())) return 0;
        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô��\n");
        if (is_vendor_good(arg) == "")
                return notify_fail(this_object()->name()+"������һ��:"+ob->query("name")+"?������ò��ã�\n");
        value = ob->query("value");
        if (value < 30)
                write(ob->query("name") + "һ�Ĳ�ֵ��\n");
        else {
                message_vision("$N������һ" + ob->query("unit") + 
                ob->query("name") + "��$n��\n", this_player(), this_object());
                MONEY_D->pay_player(this_player(), value * 70 / 100);
                if (value < 50)
                        destruct(ob);
                else
                        ob->move(this_object());
        }
        return 1;
}
