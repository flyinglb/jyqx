// feng.c ������

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "feng qingyang", "feng", "qingyang" }));
        set("title", "��ɽ��ʮ�������ڳ���");
        set("long", 
"����ǵ������𽭺��Ļ�ɽ���޷�������������ۣ��������������ֽ��
����ݳ���ü���һֱ������һ�ɵ�����������ɫ����Ȼ�Ե���Ľ�����
��
֮��һֱ����������\n");
        set("gender", "����");
        set("age", 68);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        
        set("qi", 4800);
        set("max_qi", 4800);
        set("jing", 3600);
        set("max_jing", 3600);
        set("neili", 4400);
        set("max_neili", 4400);
        set("jiali", 200);

        set("combat_exp", 1750000);
        set("score", 200000);

        set_skill("cuff", 200);
        set_skill("force", 180);
        set_skill("blade", 200);
        set_skill("dodge", 180);
        set_skill("parry", 200);
        set_skill("sword", 220);
        set_skill("strike", 200);
        set_skill("zixia-shengong", 200);
        set_skill("poyu-quan", 170);
        set_skill("fanliangyi-dao", 180);
        set_skill("huashan-sword", 200);
        set_skill("hunyuan-zhang", 170);
        set_skill("lonely-sword", 200);
        set_skill("feiyan-huixiang",200);
        set_skill("literate", 120);

        map_skill("cuff", "poyu-quan");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "lonely-sword");
        map_skill("sword", "lonely-sword");
        map_skill("blade", "fanliangyi-dao");
        map_skill("strike", "hunyuan-zhang");

        create_family("��ɽ��", 12, "����");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.poqi" :),
//              (: perform_action, "sword.pozhang" :),
//              (: perform_action, "sword.pojian" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        int student_num;
        string temp;
        string line;

        if ((int)ob->query("betrayer") )
        {
                command("say ���ҿ�" + RANK_D->query_respect(ob) + "����ݹ����ɵ�ʦ����������Ҳ���ʺ�ѧ���¾Ž���");
                return;
        }
/*
        if ((int)ob->query("mud_age") - (int)ob->query("feng_dietime") < 259200 )
        {
                command("say " + RANK_D->query_respect(ob) + "�����ԭ�����ҵ�ͽ���᣿");
                return;
        }
*/
        temp = read_file("/data/FENG", 1, 1);
        student_num = atoi(temp);

        line = "������˵�����������ڹ���" + temp + "��ͽ�ܡ���\n";
        write(line);

        if ( student_num == 3)
        {
                command("say �������ˣ����Ѿ���������ͽ���ˡ�");
                return;
        }

        if ((string)ob->query("family/family_name") != "��ɽ��")
        {
                command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α������������أ�");
                return;
        }

        if (((int)ob->query_skill("sword",1) < 80) || ((int)ob->query_skill("huashan-sword",1) < 80))
        {
                command("say �ҿ�" + RANK_D->query_respect(ob) + "�Ļ�ɽ������ûѧ���Ұɡ�");
                return;
        }
        if (((int)ob->query_skill("force",1) < 80) || ((int)ob->query_skill("zixia-shengong",1) < 80))
        {
                command("say �ҿ�" + RANK_D->query_respect(ob) + "����ϼ�񹦻�ûѧ���Ұɡ�");
                return;
        }
        if (((int)ob->query_skill("dodge",1) < 80) || ((int)ob->query_skill("feiyan-huixiang",1) < 80))
        {
                command("say �ҿ�" + RANK_D->query_respect(ob

) + "�ķ�����軹ûѧ���Ұɡ�");
                return;
        }
        if ( (int)ob->query_skill("literate",1) < 100)
        {
                command("say �ҿ�" + RANK_D->query_respect(ob) + "�Ķ���ʶ�ֻ�ûѧ���Ұɡ�");
                return;
        }

        if ((int)ob->query("shen") < 50000)
        {
                command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }

        if ((int)ob->query_int() < 20)
        {
                command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ�Ҷ��¾Ž���");
                return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "swordsman")
                ob->set("class", "swordsman");

        student_num++;
//      temp = itoa(student_num);
        if(student_num == 1)
                temp = "1";
        else if(student_num == 2)
                temp = "2";
        else if(student_num == 3)
                temp = "3";
        write_file("/data/FENG", temp, 1);
}

