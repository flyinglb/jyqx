//mu.c

#include <ansi.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
        set_name("ľ����", ({ "mu", "wood" }));
        set("long", "������������֮ɫ������͵��������ųơ�Ҷ����¶����\n"
                   +"ֻ��������ϡϡ���䣬أ�Ժڶ���٣���һ����ȴ�������ơ�\n"
                   +"����������ʵ����͡�\n"
                   );
        set("title", "���͵���");
        set("gender", "����");
        set("age", 75);
        set("nickname", HIB "Ҷ����¶" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 30);
        set("int", 29);
        set("con", 30);
        set("dex", 28);

        set("qi", 900);
        set("max_qi", 900);
        set("jing", 900);
        set("max_jing", 900);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);

        set("combat_exp", 1500000);
        set("score", 200000);
        set_skill("force", 170);
        set_skill("unarmed", 100);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("hand",170);
        set_skill("staff", 170);

//      set_skill("yanyangong", 200);
        set_skill("jinwu-daofa", 150);
//      set_skill("xiake-zhangfa", 100);
        set_skill("lingxu-bu", 150);

//      map_skill("force", "yanyangong");
        map_skill("dodge", "lingbo-weibu");
//      map_skill("unarmed", "xiake-zhangfa");
//      map_skill("hand", "xiake-zhangfa");
        map_skill("parry", "jinwu-daofa");
        map_skill("staff", "jinwu-daofa");

        create_family("���͵�",1, "����");
        set("inquiry",([
           "������" :   "������ֻ����Ե�ˣ���֪���Ƿ�������������\n",
           "ͭ��"   :   "�����û�������գ�������Ҫ�Ļ������ұ�����һ�ʡ�\n",
        ]) );
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        add_money("gold",2);
}

void attempt_apprentice(object ob)
{
        message_vision("ľ��������$N��ͷ��΢΢ҡ��ҡͷ��\n",ob);
//        command("recruit " + ob->query("id"));
        return;
}

int accept_object(object who, object ob)
{
        object obn;
        object room;
        object key;

        if ( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("��û�����������\n");
             command("smile");
        if( (string)ob->query("name") == "����ͭ��" )
        {
            if( (string)ob->query_temp("own") != (string)who->query("name") )
            {
                 message_vision("�ⲻ����Ķ�����\n",who);
                 return 0;
            }
            command(" say  ԭ����" + (string)who->query("name") + "����" +
                "��ӭ���ٱ�����");

            obn=new("/d/xiakedao/obj/labazhou");
            obn->move(who);
            command(" say  ���Ǳ����ز������࣬��߿ɲ��׺ȵ�����������Ҫ��һζ��<�ϳ�ʴ�Ǹ��Ĳ�>��"
               + "��" +  RANK_D->query_respect(who) + "Ҳ����Ե֮�ˣ�����Ⱥȣ�����Ч��������");
            message_vision("ľ����������һ��������",who);
            if( who->query_temp("zhou") == 1)
            {
                 command(" say ������ʿ��Ե����л���һ�����־���������ɣ�");
                 message_vision("ֻ����һ��¡¡��������Զ������\n", this_player());
                 who->set_temp("zhou", 0);
                 message_vision("ֻ����������ʯ�建�����˿�����¶��һ������������\n", this_player());
                 environment(who)->set("exits/enter", "/u/noz/test/mishi");

                 room=environment(who);
                 remove_call_out("close");
                 key = new("/d/xiakedao/obj/key");
message_vision("���������ʯ�ŵ�Կ�ף�Ҳ�����͵��ϵ�ƾ֤��ϣ�������Ʊ��ܣ��������ⶪ����" +
                    "�����ɽ������ˣ��뵺ʱӦ��黹��\n", who);
                 key->move(who);
                 call_out("close", 15, room);
                 return 1;
            }
            who->set_temp("zhou", 2);
            return 1;
        }
        else
        {
            message_vision("�Ҳ���Ҫ�ⶫ����\n",who);
            return 0;
        }
}

void close(object room)
{
        message("vision","��¡¡���������֮��ʯ���ֺ����ˡ�\n", room);
        room->delete("exits/enter");
}

