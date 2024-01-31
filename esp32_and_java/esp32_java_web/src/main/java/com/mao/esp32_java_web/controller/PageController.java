package com.mao.esp32_java_web.controller;

import com.mao.esp32_java_web.Service.PageService;
import com.mao.esp32_java_web.entity.Result;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@Controller
@RestController
@RequestMapping("/page")
public class PageController {
    @Autowired
    private PageService pageService;

    // 展示esp32连接的结果，测试作用
    @GetMapping("/test")
    public Result test(){
        String str = pageService.test();
        return Result.success(str);
    }
}
