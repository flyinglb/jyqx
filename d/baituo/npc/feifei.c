               //feifei.c
inherit NPC;
void greeting(object);
void do_dest(object ob);
void init();
void create()
{
        set_name("�ʷ�", ({ "fei fei","fei" }) );
        set("gender", "����" );
        set("age", 35);
        set("long", "һ����ͷ����ĳ�ʦ����ֻС�۾���ͣ��գ���š�\n");
        set("shen_type", -1);
        set("combat_exp", 10000);
        set("str", 20);
        set("dex", 22);
        set("con", 20);
        set("int", 21);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver",50);
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
//        object obn;
        if( !ob || environment(ob) != environment() ) return;
        if(((string)ob->query("family/family_name")=="����ɽ��")&&(random(3)==1))
        {say("�ʷ�Ц������˵������λ" + RANK_D->query_respect(ob)
             + "�����˰ɣ����ò͡�\n");
//           obn=new("/d/baituo/obj/cake");
//           obn->move(environment(ob));
//           obn=new("/d/baituo/obj/doujiang");
//           obn->move(environment(ob));
           }
        else 
             say("�ʷ�С��һգ��Ц������˵������λ" + RANK_D->query_respect(ob)
             + "����ӭ���ιۣ��ɲ�Ҫ͵��Ӵ��\n");
           return;
}
int accept_object(object who, object ob)
{
        object obn;

        if( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("��û�����������\n");
        if (  (string)ob->query("id") != "mu chai"  )
           return notify_fail("�ʷʲ�Ҫ���������\n");
        command("smile "+(string)who->query("id"));

        obn = new("/clone/money/silver");
        obn->set_amount(10);

        if (random(3)==1) {
                obn->set_amount(12);
                obn->move(who);
                tell_object(who,"�Ҷ����������ӣ���Ҫ���ţ�\n");
        } else {
                obn->move(who);
                tell_object(who,"�ٽ��������Ժ��һ����ô��ģ�\n");
        }
        call_out("do_dest",1,ob);
        return 1;
}

void do_dest(object ob)
{
        ob->move(VOID_OB);
        destruct(ob);
}
