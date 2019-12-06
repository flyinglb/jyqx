// seller.c

inherit NPC;
inherit F_VENDOR;

string ask_me();
void destroy(object ob);

void create()
{
        set_name("С��", ({ "seller" }) );
        set("gender", "����" );
        set("age", 32);
        set("long",
                "���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
        set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/stick",
                __DIR__"obj/bottle",
                __DIR__"obj/egg",
                "/d/xingxiu/obj/fire",
        }) );
        set("inquiry", ([
                "ҩ" : (: ask_me :),
                "ҩ��" : (: ask_me :),
        ]) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("coin", 100);
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy", "buy");
}

string ask_me()
{
        object me=this_player();
        if ( me->query_temp("tmark/ҩ")) {
                return "�����ϴ�����û��������ô���µ��ˣ�\n";
        }
        else {
                me->set_temp("tmark/ҩ",1);
                return "�����ҵ�����ɭ���в�ҩ������������һЩ��ҩ�ģ�Ҫ����Ƚ�
Ǯ��\n";
        }
}

int accept_object(object who, object ob)
{
        object obj;

        if ((ob->query("money_id")) && (ob->value() >= 10000)
         && (who->query_temp("tmark/ҩ")))
        {
                obj = new(__DIR__"obj/shouwu");
                obj->move(who);
                who->add_temp("tmark/ҩ",0);
                write("С��˵��������Ȼ���������Ǯ����ζҩ�ɾ͹����ˡ���\n");
                call_out("destroy",1,ob);
                return 1;
        }
        else
                if (ob->query("money_id"))
                {
                        write("С����Цһ����˵�������ٺ٣�������ô��Ǯ�ġ���\n");
                        call_out("destroy",1,ob);
                        return 1;
                }
                else {
                        return notify_fail("С�������˵���������������ʲô����\n");
                }
}
void destroy(object ob)
{
        if(!ob) return;
        ob->move(VOID_OB);
        destruct(ob);
}
