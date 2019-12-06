// shizhongyu.c ʯ����

inherit NPC;

void create()
{
        set_name("ʯ����", ({ "shi zhongyu", "shi", "zhongyu" }));
        set("gender", "����");
        set("age", 20);
        set("str", 15);
        set("int", 45);
        set("con", 18);
        set("dex", 20);
        set("per", 30);
        set("long", "����һ�����ṫ�ӣ���Լ��ʮ�����꣬��������֮�£�ɫ�紺��
֮�����������ã�\n"
            "ü��ī�������������������ﲨ����ŭ��ʱЦ�����Ӷ����顣\n");
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("score", 0);
        set("attitude", "peaceful");

        set_skill("unarmed", 30);
        set_skill("force", 30);
        set_skill("blade", 20);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("literate",100);

        set_skill("wuhu-duanmendao", 50);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/armor", 5);
        set_temp("apply/damage", 10);
        map_skill("blade", "wuhu-duanmendao");

        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 20);
        set("inquiry", ([
                "���͵�" : "��Ȫ�ݸ�����һ��С����\n",
                "ʯ����" : "�����ҵ����ֵܣ������������͵���\n"
                           "��������ɱ����˴������̻��ѽ��\n",
//                "hop"    : "���ǽ�ש��Ů��ѽ���Һܳ��������\n",
//                "young"  : "�����ҵ�����ѽ��\n",
//                "host"   : "��̫С�����ˣ�˭��֪�����������������˰���\n",
//                "wind"   : "�Ҿ������Ĵ���������û������\n",
//                "shaw"   : "����������MUD�е���������\n",
//                "aman"   : " �ҵ�Ȼ֪���ˣ��Ҽ�����ѽ��\n",
//                "xmo"    : "СĪ���������Ǻ�����ѽ�����Ǿ�����һ���档\n",
//                "mudos"  : "����!����Ҳ�Ǻ�����ѽ! \n",
//                "road"   : "ѽ������˭ѽ? ��ô������֪���ۡ��������µĽ��ѽ��\n"
//                           "�����Ǹ��ú��ӣ����Ǹ��о����أ�����������������һ��ͺ��ˡ�\n",
//                "xinyue" : "�������ˣ�һ�����ֺ��У�һ��Ҳ�������Ľ�㡣\n",
                "����"   : "�Һþ�û�������ˣ���֪����������ô���ˡ�\n",
                "���Ʒ�����" : "������������Ե����͵�ѧ�书ѽ��\n",
        ]) );
        set("chat_chance", 8);
        set("chat_msg", ({
                "\nʯ����˵��: ������������ѽ���Һ�����ѽ��\n",
                "\nʯ����̾��: Ҳ��֪���ҵĶ�����ô���ˡ�\n",
                "\nʯ����˵��: ��������Ǻö���...\n",
                "\nʯ����˵��: ����˭�ܰ���ɱ���������ͷ���ֵ���лл���ˣ�\n",

        }) );
        setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}

void init()
{
        object ob;
        ob = this_player();
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() )
                return;
        message_vision( "\nʯ���������Ц���������ڿ������ҵ������ˡ�\n",this_object());
}

void die()
{
        say("\nʯ����˵�����һ��и���Ըû�ˣ�ϣ�����ܰ����չ˶�����\n");

        message_vision("ʯ�����Ŷ��������֣����ˣ�\n", this_object());
        ::die();
}

int accept_object(object who, object ob)
{
        object obn;

        if( !who || environment(who) != environment() )
                return 0;
        if ( !objectp(ob) )
                return 0;
        if ( !present(ob, who) )
                return notify_fail("��û�����������");

        if ( (string)ob->query("id") == "shou pa")
        {
                remove_call_out("destroy");
                call_out("destroy", 1, who, ob);

                message_vision("\nʯ����ж�������ӭ��������֪����������Ϣ�ˣ�\n",who);
                obn = new("/d/xiakedao/obj/shane-bu");
                obn->move(who);
                return 1;
        }
}

void destroy(object me, object ob)
{
        destruct(ob);
        return;
}
