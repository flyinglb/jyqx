// random_name.c
// npc 随机姓名

//mapping man_name1 男名一
//mapping man_name2 男名二
//mapping woman_name1 女名一
//mapping woman_name2 女名二
//string* title 随机 title
// 例：   书生 戴世涛(Dai shitao)

mapping surname = ([
"赵":"zhao", "钱":"qian", "孙":"sun",  "李":"li",   "周":"zhou",
"吴":"wu",   "郑":"zhen", "王":"wang", "冯":"feng", "陈":"chen",
"褚":"zhu",  "卫":"wei",  "蒋":"jiang","沈":"shen", "韩":"han",
"杨":"yang", "朱":"zhu",  "秦":"qin",  "尤":"you",  "许":"xu",
"何":"he",   "吕":"lv",   "施":"shi",  "张":"zhang","孔":"kong",
"曹":"cao",  "严":"yan",  "华":"hua",  "金":"jin",  "魏":"wei",
"陶":"tao",  "姜":"jiang","戚":"qi",   "谢":"xie",  "邹":"zhou",
"喻":"yu",   "柏":"bo",   "水":"shui", "窦":"dou",  "章":"zhang",
"云":"yun",  "苏":"su",   "潘":"pan",  "葛":"ge",   "奚":"xi",
"范":"fan",  "彭":"peng", "郎":"lang", "鲁":"lu",   "韦":"wei",
"昌":"chang","马":"ma",   "苗":"miao", "凤":"feng", "花":"hua",
"方":"fang", "傻":"sha",  "任":"ren",  "袁":"yuan", "柳":"liu",
"邓":"deng", "鲍":"bao",  "史":"shi",  "唐":"tang", "费":"fei",
"廉":"lian", "岑":"chen", "薛":"xue",  "雷":"lei",  "贺":"he",
"倪":"ni",   "汤":"tang", "藤":"teng", "殷":"yin",  "罗":"luo",
"华":"hua",  "郝":"hao",  "邬":"wu",   "安":"an",   "常":"chang",
"乐":"le",   "呆":"dai",  "时":"shi",  "付":"fu",   "皮":"pi",
"卞":"bian", "齐":"qi",   "康":"kang", "伍":"wu",   "余":"yu",
"元":"yuan", "卜":"po",   "顾":"gu",   "盈":"ying", "平":"ping",
"黄":"huang","和":"he",   "穆":"mu",   "肖":"xiao", "尹":"yi",
"姚":"yao",  "邵":"shao", "湛":"zhan", "汪":"wang", "祁":"qi",
"毛":"mao",  "禹":"yu",   "狄":"di",   "米":"mi",   "贝":"bei",
"明":"ming", "藏":"zang", "计":"ji",   "伏":"fu",   "成":"cheng",
"戴":"dai",  "谈":"tan",  "宋":"song", "茅":"mao",  "庞":"pang",
"熊":"xiong","纪":"ji",   "舒":"su",   "屈":"qu",   "项":"xiang",
"祝":"zhu",  "董":"dong", "梁":"liang","樊":"fan",  "胡":"hu",
"凌":"ling", "霍":"huo",  "虞":"yu",   "万":"wan",  "支":"zhi",
"柯":"ke",   "昝":"jiu",  "管":"guan", "卢":"lu",   "英":"ying",
"仇":"qiu",  "候":"hou",  "岳":"yue",  "帅":"shuai","欧":"ou",
"缑":"gou",  "亢":"kang", "况":"kuang","后":"hou",  "有":"you",
"琴":"qin",  "商":"shang","牟":"mou",  "佘":"she",  "耳":"er",
"墨":"mo",   "哈":"ha",   "谯":"qiao", "年":"nian", "爱":"ai",
"阳":"yang", "佟":"dong", "第":"di",   "五":"wu",   "言":"yan",
"福":"fu",   "蒯":"kai",  "钟":"zong", "宗":"zong", "林":"lin",
"石":"shi",  "郭":"guo",  "左":"zuo",
"司马":"sima",      "上官":"shangguan", "欧阳":"ouyang",
"夏候":"xiahou",    "诸葛":"zhuge",     "闻人":"wenren",
"东方":"dongfang",  "赫连":"helian",    "皇甫":"huangpu",
"尉迟":"weichi",    "公羊":"gongyang",  "澹台":"zhantai",
"公治":"gongye",    "宗政":"zongzheng", "濮阳":"puyang",
"淳于":"chunyu",    "单于":"shanyu",    "太叔":"taishu",
"申屠":"shentu",    "公孙":"gongsun",   "仲孙":"zongsun",
"辕轩":"yuanxuan",  "令狐":"linghu",    "钟离":"zhongli",
"宇文":"yuwen",     "长孙":"changsun",  "幕容":"murong",
"司徒":"situ",      "师空":"shikong",   "颛孔":"zhuangkong",
"端木":"duanmu",    "巫马":"wuma",      "公西":"gongxi",
"漆雕":"qidiao",    "乐正":"lezheng",   "壤驷":"xiangsi",
"公良":"gongliang", "拓趾":"tuozhi",    "夹谷":"jiagu",
"宰父":"zaifu",     "谷梁":"guliang",   "楚晋":"chujing",
"阎法":"yanfa",     "汝鄢":"ruye",      "涂钦":"tuqin",
"段千":"duanqian",  "百里":"baili",     "东郭":"dongguo",
"南郭":"nanguo",    "呼延":"huyan",     "归海":"guihai",
"羊舌":"yangshe",   "微生":"weisheng",  "梁丘":"liangqiu",
"左丘":"zuoqiu",    "东门":"gongmen",   "西门":"ximen",
"佰赏":"baisheng",  "南官":"nangong",
]);

mapping man_name1 = ([
"忠":"zhong","孝":"xiao", "礼":"li",   "义":"yi",
"智":"zhi",  "勇":"yong", "仁":"ren",  "匡":"kuang",
"宪":"xian", "令":"ling", "福":"fu",   "禄":"lu",
"大":"da",   "小":"xiao", "晓":"xiao", "高":"gao",
"可":"ke",   "阿":"a",    "金":"jin",  "世":"shi",
"克":"ke",   "叔":"shu",  "之":"zhi",  "公":"gong",
"夫":"fu",   "时":"shi",  "若":"ruo",  "庆":"qing",
"文":"wen",  "武":"wu",   "多":"duo",  "才":"cai",
"长":"zhang","子":"zi",   "永":"yong", "友":"you",
"自":"zi",   "人":"ren",  "为":"wei",  "铁":"tie",
]);

mapping man_name2 = ([
"霸":"ba",   "白":"bai",  "班":"ban",  "斌":"bin",
"宾":"bin",  "昌":"chang","超":"chao", "诚":"cheng",
"川":"chuan","鼎":"ding", "定":"ding", "斗":"dou",
"法":"fa",   "飞":"fei",  "风":"feng", "锋":"feng",
"钢":"gang", "罡":"gang", "贯":"guan", "光":"guang",
"海":"hai",  "虎":"hu",   "华":"hua",  "浩":"hao",
"宏":"hong", "济":"qi",   "坚":"jian", "健":"jian",
"剑":"jian", "江":"jiang","进":"jin",  "杰":"jie",
"俊":"jun",  "康":"kang", "良":"liang","麟":"lin",
"民":"min",  "明":"ming", "鸣":"ming", "宁":"ning",
"培":"pei",  "启":"qi",   "强":"qiang","荣":"rong",
"山":"shan", "泰":"tai",  "涛":"tao",  "挺":"ting",
"伟":"wei",  "熙":"xi",   "祥":"xiang","雄":"xiong",
"旭":"xu",   "毅":"yi",   "瑜":"yu",   "羽":"yu",
"宇":"yu",   "岳":"yue",  "舟":"zhou",
]);

mapping woman_name1 = ([
"爱":"ai",   "春":"chun", "丹":"dan",  "芳":"fang",
"芬":"fen",  "凤":"feng", "姑":"gu",   "红":"hong",
"虹":"hong", "娇":"jiao", "娟":"juan", "菊":"ju",
"兰":"lan",  "岚":"lan",  "丽":"li",   "莉":"li",
"莲":"lian", "玲":"ling", "琳":"lin",  "娜":"na",
"琴":"qin",  "芹":"qin",  "倩":"qian", "萍":"ping",
"婷":"ting", "霞":"xia",  "香":"xiang","艳":"yan",
"燕":"yan",  "英":"ying", "瑛":"ying", "玉":"yu",
"珍":"zhen", "珠":"zhu",
]);

mapping woman_name2 = ([
"爱":"ai",   "春":"chun", "丹":"dan",  "芳":"fang",
"芬":"fen",  "凤":"feng", "姑":"gu",   "红":"hong",
"虹":"hong", "娇":"jiao", "娟":"juan", "菊":"ju",
"兰":"lan",  "岚":"lan",  "丽":"li",   "莉":"li",
"莲":"lian", "玲":"ling", "琳":"lin",  "娜":"na",
"琴":"qin",  "芹":"qin",  "倩":"qian", "萍":"ping",
"婷":"ting", "霞":"xia",  "香":"xiang","艳":"yan",
"燕":"yan",  "英":"ying", "瑛":"ying", "玉":"yu",
"珍":"zhen", "珠":"zhu",
]);

mapping man_name()
{
        mapping name;
        string* sn = keys(surname);
        string* n1 = keys(man_name1);
        string* n2 = keys(man_name2);
        int i, j, k;
        i = random(sizeof(sn));
        j = random(sizeof(n1));
        k = random(sizeof(n2));
        
        name = ([
                "name" : sn[i]+n1[j]+n2[k],
                "id" : ({surname[sn[i]]+" "+man_name1[n1[j]]+man_name2[n2[k]],
                surname[sn[i]]+man_name1[n1[j]]+man_name2[n2[k]],
                surname[sn[i]], man_name1[n1[j]]+man_name2[n2[k]],}),
        ]);
        return name;
}

//因为没有 woman_name1 列表，此函数无法使用
mapping woman_name()
{
        mapping name;
        string* sn = keys(surname);
        string* n1 = keys(woman_name1);
        string* n2 = keys(woman_name2);
        int i, j, k;
        i = random(sizeof(sn));
        j = random(sizeof(n1));
        k = random(sizeof(n2));
        
        name = ([
                "name" : sn[i]+n1[j]+n2[k],
                "id" : ({surname[sn[i]]+" "+woman_name1[n1[j]]+woman_name2[n2[k]],
                surname[sn[i]]+woman_name1[n1[j]]+woman_name2[n2[k]],
                surname[sn[i]], woman_name1[n1[j]]+woman_name2[n2[k]],}),
        ]);
        return name;
}
