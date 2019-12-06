// qiaofu.c

inherit NPC;
int inquiry_dao();

void create()
{
        set_name("�Է�", ({ "qiao fu","fu" }) );
        set("gender", "����" );
        set("age", 50);
        set("long", "һ��һ�����Կ���Ϊ�������Է����ڱ��ܷ�˪���Գ������䲻��Ƶ�˥�ϡ�\n");
        set("shen_type",1);
        set("combat_exp", 10000);
        set("str", 17);
        set("dex", 18);
        set("con", 18);
        set("int", 18);
        set("attitude", "friendly");
        set("inquiry" , ([
            "��" : (: inquiry_dao :),
            "��" : (: inquiry_dao :),
        ]));
        set_temp("buyed", 0);
        setup();
        carry_object("/clone/misc/cloth")->wear();

}

int accept_object(object who, object ob)
{
        command("smile");
        message_vision("лл���ĵĴ�ү�������кñ���\n", who);
        if( ob->query("money_id") && ob->value() >= 3000  )
           set_temp("buyed", 1);
        return 1;
}

int inquiry_dao()
{
        object me=this_player();
        object ob;

        if (present("cut knife",me))
        {
            message_vision("��ͱ�Ѱ��ͷ�ӿ����ˣ������ϲ���Ҳ��һ����?\n", me);
            return 1;
        }
        if( query_temp("buyed")==0 )
        {
            message_vision("��λ��ү��ʵ�ڲ������᲻���⵶��С��һ�Ҿ�ȫ������\n"
                  "�����ˣ������㣬������ô�����\n", me);
            return 1;
        }
        if( query_temp("buyed")==1 )
        {
            message_vision("��Ȼ��������Ҫ���͸���ɣ�����ʷ����Ҫ�Һúñ��ܵģ�\n"
                  "���ǧ���Ϲ�͸����ˣ��������������ġ�\n", me);
            ob=new("/d/xiakedao/obj/knife");
            ob->move(me);
            message_vision("�Է�ݸ���һ�Ѳ񵶣�\n", me);
            set_temp("buyed", 0);
        }
        return 1;
}
