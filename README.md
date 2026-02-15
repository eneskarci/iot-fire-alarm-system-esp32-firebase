# IoT Temelli Yangın Alarm Sistemi (ESP32 + Firebase)


Bu proje Mühendislik Tasarımı 1 dersi kapsamında tarafımdan geliştirilmiştir.

İzinsiz kopyalanması veya akademik amaçla teslim edilmesi yasaktır.
Lütfen kendi emeğinizle çalışın. Kullanmak isterseniz önce benimle iletişime geçiniz.


🇹🇷 TÜRKÇE
============================================================

## Proje Özeti

Bu proje ESP32 tabanlı IoT temelli bir yangın alarm sistemidir.
Sistem sensör verilerini gerçek zamanlı izler, eşik değerleri aşıldığında alarm üretir
ve verileri Wi-Fi üzerinden Firebase veritabanına aktarır.

Ayrıca yerel ağ üzerinden erişilebilen bir web arayüzü (local web page) ile
anlık izleme sağlanır.

Geliştirme ortamı: Arduino IDE


## Kullanılan Teknolojiler

- ESP32 + Wi-Fi bağlantısı
- Firebase (veritabanı / database)
- Local Web UI (lokalde çalışan web sayfası)
- Arduino IDE


## Temel Özellikler

- Gerçek zamanlı sensör okuma
- Eşik değer bazlı alarm tetikleme (buzzer/LED vb.)
- Wi-Fi üzerinden veri iletimi
- Firebase veritabanına kayıt (uzaktan izleme / log)
- Yerel web arayüzü üzerinden izleme


## Proje Yapısı

- src/          → ESP32 (Arduino) kaynak kodları
- Images/       → Proje görselleri
- weblocal.html → Yerel web arayüzü


🇬🇧 ENGLISH
====

## Project Overview

This project is an ESP32-based IoT Fire Alarm System.
It monitors sensor data in real time, triggers an alarm when thresholds are exceeded,
and sends telemetry over Wi-Fi to a Firebase database.

A local web interface (running on the local network) is also provided for
real-time monitoring.

Developed using Arduino IDE.


## Technologies

- ESP32 + Wi-Fi
- Firebase (database)
- Local Web UI (local webpage)
- Arduino IDE


## Key Features

- Real-time sensor monitoring
- Threshold-based alarm triggering (buzzer/LED, etc.)
- Wi-Fi data transmission
- Firebase database logging (remote monitoring / history)
- Local web interface for live monitoring
- Serial debug output


## Repository Structure

- src/          → ESP32 (Arduino) source code
- Images/       → Project images
- weblocal.html → Local web interface

