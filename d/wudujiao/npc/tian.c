// tian.c  ��ɩ
inherit NPC;
void create()
{
        set_name("��ɩ", ({"tian sao","tian","sao"}));
        set("title", "Ů����");
        set("gender", "Ů��" );
        set("age", 36);
        set("long", "һ�������������긾�ˣ�\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        setup();
        carry_object("/d/city/obj/cloth")->wear();

}
void init()
{
::init();
        add_action("do_yao", "yao");
}
int do_yao(string arg)
{
        object m,mm;
        message_vision("$N����ɩ�ʵ�����ɩ����������\n", this_player());
        if((int)this_player()->query("food") >=
(int)this_player()->max_food_capacity()*90/100 )
        return notify_fail("��ɩЦ����û�ǣ��ȿ���ʱ�����ɣ�\n");
        if((present("baozi", this_player())))
        return notify_fail("��ɩЦ������Ҫ��������ģ������Ź���ģ�\n");
	
	if ( present("baozi", environment()) )
                return notify_fail("��ɩЦ�����ǲ�����һ�����������˵��\n");
        m=new(__DIR__"obj/baozi2");
        mm=new(__DIR__"obj/baozi2");
        m->move(this_player());
        mm->move(this_player());
        message_vision("��ɩ��$NЦ�������˰ɣ�����ԡ�\n", this_player());
return 1;
}
