// rong.c ����

inherit NPC;
inherit F_MASTER;

string ask_chicken();
void greeting(object who);

void create()
{
    set_name("����", ({"huang rong", "huang", "rong"}));
    set("title", "�һ�����������Ů");
    set("gender", "Ů��");
    set("age", 18);
    set("long", 
        "�����һ������Ķ���Ů�������ڵ����������������������Ů�������۰���\n"
        "���������ѷ��ϲ���Ĵ����ܡ�\n");

    set("attitude", "peaceful");
    set("class", "scholar");
        
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 800);
    set("max_qi", 800);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 0);
        
    set("combat_exp", 200000);
    set("score", 0);
        
    set_skill("force", 60);
    set_skill("bibo-shengong", 80);
    set_skill("unarmed", 80);
    set_skill("xuanfeng-leg", 80);      // ����ɨҶ��
    set_skill("strike", 80);            // �����Ʒ�
    set_skill("luoying-zhang", 80);
    set_skill("dodge", 150);
    set_skill("anying-fuxiang", 100);
    set_skill("parry", 85);
    set_skill("literate",150);           // ����ʶ��
    set_skill("sword", 80);
    set_skill("luoying-shenjian",80);
        
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("strike" , "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
        
    create_family("�һ���", 2, "����");

        set("inquiry", ([
                "��ҩʦ" : "����ѽ, ����������? ",
                "����"   : "��ô? �����Ҿ�������Ϣ��? ",
                "���߹�" : "ʦ�������˼Ҿ�ϲ���Խл���! ",
                "�л���" : (: ask_chicken :)
        ]) );

    setup();
    carry_object(__DIR__"obj/ruanwei")->wear();
    carry_object(__DIR__"obj/shudai")->wear();

}

void init()
{
        object ob;
        mapping myfam;

        ::init();
        add_action("do_kiss", "kiss");
        if (interactive(ob = this_player()) && !is_fighting()) {
                myfam = (mapping)ob->query("family");
                if ((!myfam || myfam["family_name"] != "�һ���") &&
                        (!wizardp(ob)))
                {
                        remove_call_out("saying");
                        call_out("saying",2,ob);
                }
        }
        remove_call_out("greeting");
        call_out("greeting", 1, this_player() );
}

void greeting(object who)
{
        object room, env = environment();
        
        if( !who || !env || environment(who) != env ) return;
        if( !room = find_object("/d/taohua/wofang") )
                room = load_object("/d/taohua/wofang");
        if( env != room) {
                message_vision("����¶���Ի���������¿��˿������Թ˵����˳�ȥ��\n");
                this_object()->move(VOID_OB);
                destruct(this_object());
        }
}

int do_kiss ( string arg )
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="rong" )
     return 0;
   
   if ( (string) ob -> query ("gender") == "����" )
      command ("say ����������������"+ ob->query("name") + "Ҫ�����ң�\n") ;
   else
      message_vision("\n���ض�$NЦ�������ý�㲻Ҫ����������������\n", ob);
   return 1 ;
}

void saying(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    if ((string)ob->query("gender") == "����")
        message_vision("\n�������־���֮ɫ��������$Nһ�ۣ�˵����������ʲô�ˣ�"
        "�����Ҵ��ҵĹ뷿��\n�ٲ�����ȥ��������ô���㣡��\n", ob);
    else
        message_vision("\n���ؿ��˿�$N��˵�������þ�û���������ˣ�"
        "��֪��λ�������Ҿ�������Ϣ��\n", ob);
}

void attempt_apprentice(object ob)
{
   if ((int)ob->query_temp("marks/�ض�")==1)
   {
      say( "����һ��Ц�⣺����л����������Ŀ���!��\n");
      say( "��������һЦ���Ҳ���ͽ��..��Ҳ�����������������⫼׾��͸���ɣ�\n");
      new("/kungfu/class/taohua/obj/ruanwei")->move(ob);
      tell_object(ob,"���ش���������һ����⫼׵ݸ��㡣\n");
      ob->set_temp("marks/�ض�",2);
   }
   else
    command("say �������ôС����ͽ�ܣ�������Ц��������");
}

string ask_chicken()
{
        if (this_player()->query_temp("marks/��", 1))
                return "���������ô��ô������˵����ꤻ���\n";
        else
        {
                say("�ض�������˵���л������Ǻ��������ز����ҵ�������˺ô�ľ��Ÿ㵽������\n"
                        "�����ط�������������ʲô��\n");
                this_player()->set_temp("marks/��", 1);
                return "����Գ�ȥ�ˡ�\n";
        }
}