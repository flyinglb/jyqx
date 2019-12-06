// shipotian.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int ask_weiwang();

void create()
{
        set_name("ʯ����", ({"shi potian", "shi","potian"}));
        set("title", "���ְ����");
        set("gender", "����");
        set("age", 20);
        set("long", "����Լ��ʮ���꣬����һ�����õ��·���ȴҲ����ס��һ���Ӣ����\n");

        set("attitude", "peaceful");

        set("str", 25);
        set("int", 35);
        set("con", 25);
        set("dex", 25);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);

        set("combat_exp", 1000000);
        set("score", 30000);

        set_skill("force", 100);                 // �����ڹ�
        set_skill("huntian-qigong", 150);        // ��������
        set_skill("unarmed", 100);               // ����ȭ��
        set_skill("xianglong-zhang", 150);       // ����ʮ����
        set_skill("dodge", 100);                 // ��������
        set_skill("xiaoyaoyou", 150);            // ��ң��
        set_skill("parry", 100);                 // �����м�
        set_skill("begging", 50);               // �л�����
        set_skill("checking", 50);              // ����;˵

        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");
        set("chat_chance", 8);
        set("chat_msg", ({
        "ʯ����˵��: �������͵���ô�����ˣ�Ҳ��֪�����������������ô���ˡ�\n",
        "ʯ����˵: ������������Ҫ�������ߴ��кô�����\n",
        "ʯ����ͻȻ˵��: ���У��Ҳ����İ��壬��Ҫȥ��������\n",
        "ʯ����ͻȻ˵��: �ӣ��ҵ�������ô������һȺ����ڶ��ء�\n",
        "ʯ����˵��: ���ܸ��������̻����? \n",
        }));
        set("inquiry", ([
                "������" :  "\n��ȥ����������������������ɡ�\n",
                "ʯ����" :  "\n�����ҵ��ֵܣ���������Ħ���¡�\n",
                "����" :  "\nѽ�����������?�����ðɡ�\n",
                "�����̻��" : "\n�������������͵�תת�ɡ�\n",
                "���Ʒ�����" : "\n�����������Ҫ�����ࡣ\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
        ]) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

int ask_weiwang()
{
        command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
        say("\nʯ����˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
                +"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
        say("\nʯ������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
        return 1;
}

int recognize_apprentice(object ob)
{
        if (ob->query("weiwang")<50)
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+"������̫�ͣ��Ҳ��ܽ��� ��\n");
                return 0;
        }
        return 1;
}

void init()
{
        ::init();
        add_action("do_skills","skills");
        add_action("do_skills","cha");

}

int do_skills(string arg)
{
        object ob ;
        ob = this_player () ;
        if(wizardp(ob))
                return 0;
        if (ob->query("weiwang")<50)
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����ô�ܿ��ҵ��书�ء�\n");
                return 1;
        }
        command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �л����� (begging)                       - �������  50/   \n"+
"  ����;˵ (checking)                      - �������  50/   \n"+
"  �����Ṧ (dodge)                         - һ����ʦ  100/   \n"+
"  �����ڹ� (force)                         - һ����ʦ  100/   \n"+
"���������� (huntian-qigong)                - һ����ʦ  150/   \n"+
"  �����м� (parry)                         - �Ƿ��켫  100/   \n"+
"  ����ȭ�� (unarmed)                       - һ����ʦ  100/   \n"+
"������ʮ���� (xianglong-zhang)             - �Ƿ��켫  150/   \n"+
"����ң�� (xiaoyaoyou)                      - һ����ʦ  150/   \n");
        return 1;
}

int accept_object(object who, object ob)
{
        object obn;
        if( !who || environment(who) != environment() )
                return 0;
        if( !objectp(ob) )
                return 0;
        if( !present(ob,who) )
                return notify_fail("��û������������\n");

        if( (string)ob->query("id") == "xuanbingbihuo jiu")
        {
                remove_call_out("destroy");
                call_out("destroy", 1, who, ob);

                message_vision( "\nʯ���켤����˵����λ��磬�Ҹ���ôл���ء�\n",who);
                obn = new("/d/xiakedao/obj/xuantie");
                obn->move(who);
                return 1;
        }
}

void destroy(object me, object ob)
{
        destruct(ob);
        return;
}
