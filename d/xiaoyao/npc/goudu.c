// goudu.c
// edward 2000.3

inherit NPC;
//inherit F_MASTER;

#include <ansi.h>

string ask_me();

void create()
{
        set_name(HIC"����"NOR, ({ "gou du", "gou" }));
        set("long", 
                "������ȥҲ�Ǽ�ʮ������ˣ�ȴ�Ǵ�Ȼһ������ӵ�ģ����\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "friendly");
        set("class", "scholar");
        set("shen_type", 1);
        set("str", 25);
        set("int", 35);
        set("con", 25);
        set("dex", 25);

        set("inquiry", ([
                "����":(:ask_me:),
        ]) );

        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 60);
        set("combat_exp", 150000);
        set("score", 40000);

        set_skill("blade",70);
        set_skill("ruyi-dao",70);
        set_skill("force", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
        set_skill("parry", 70);
        set_skill("lingboweibu", 70);
        set_skill("beiming-shengong",70);
        set_skill("zhemei-shou", 70);
        set_skill("literate", 150);

        map_skill("unarmed", "zhemei-shou");
        map_skill("dodge", "lingboweibu");
        map_skill("force", "beiming-shengong");
        map_skill("blade", "ruyi-dao");

        set("book_count", 1);

        create_family("��ң��", 3, "����");
        set("title","��ң��"MAG"�����Ȱ��ѡ�"NOR);
        set("nickname",HIY"���"NOR);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/blade")->wield();

}


string ask_me()
{
        object me,ob;
        ob=this_player(); 

        if (query("book_count") < 1)
                return "�������ˣ��Ǳ�"HIY"�����"NOR"���Ѿ����͸������ˡ�";   
        add("book_count", -1);                  

        if(ob->query("family/master_id")=="xiaoyao zi")
        {
                command("say ʦ����Ҫ"HIY"�����"NOR"����ȥ���ǡ�");
                message_vision(HIY"�����ӻ����ͳ�һ��"MAG"����"NOR"�����˸�$N \n\n"NOR,ob);
                me=new("/clone/book/lbook4");
                me->move(ob);
                return RED"�Ȿ���ǧ��Ҫ������˰�������һ��Ͳ������ˡ�\n"NOR;
        }
        command("say ������"HIY"�����"NOR"��û���ˣ����������ɸ��ִ����ֵ������顣");
        command("say ��Ȼ����ô��ѧ���ҾͰ����͸���ɡ�\n");
        message_vision(HIY"�������䵹�����˰��죬�ҳ�һ��"MAG"����"HIY"�����˸�$N \n\n"NOR,ob);
        if (random(2) == 1) me=new("/clone/book/strike_book");
        else me=new("/clone/book/book-paper");
        me->move(ob);

        return RED"�Ȿ���ǧ��Ҫ������˰�������һ��Ͳ������ˡ�\n"NOR;
}

